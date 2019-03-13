#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "opcodeTable.h"
#include "symbolTable.h"
#include "utility.h"

/*
 * Method to parse opcode file and insert sybmols into binary tree
 */
BSTTree* parseInstructionSet(FILE* instructionFile, int size) {

    char instruction[6];
    int opcode, format;
    BSTTree* tree = newTree(size);

    while (fscanf(instructionFile, "%6s%d%d", instruction, &opcode, &format) == 3) {
        insert(tree, instruction,  opcode, format);
    }
    
    return tree;
}

/*
 * Computes and location value for a given label
 */
int computeLocCtr(char* label, char* instruction, BSTTree* instructionSet) {
    int found = 0, locctr = 0;
    int val = getFormat(instructionSet, instruction, &found);
    if (!found) {
        val = 1;
    }

    if(strcmp(instruction, "word") == 0) {
        locctr += 3;
    }
    else if (strcmp(instruction, "resw") == 0) {
        locctr += 3 * atoi(instruction);
    }
    else if(strcmp(instruction, "resb") == 0) {
        locctr += atoi(instruction);
    }
    else if(found) {
        locctr += val;
    }
    return locctr;
}

void parseLine(char* line, char** label, char** instruction) {
    int num = 0, i;
    if (line[0] == '\t') {
        if (*label != NULL) {
            free(*label);
            *label = NULL;
        }

        i = 0;
    }
    else {
        int j = 0;
        for (i = 0; line[i] != ' '; ++i);
        copy(label, line, 0, i);
    }

    if (*instruction != NULL) {
        free(*instruction);
        *instruction = NULL;
    }
    {
        int j = 0, k = ++i;
        for (; line[i] != ' ' && line[i] != 0; ++i, ++j);
        if (line[i] == 0) --j;
        copy(instruction, line, k, j);
    }

    //We don't need to parse args here, so skipping it
}

void assemblerPass(FILE* programFile, BSTTree* instructionSet, HashTable* symbolTable) {
    
    char line[50]; //Line buffer of 50 characters
    char *label = NULL, *instruction = NULL;
    int locctr = 0, firstLine = 1;

    while (fgets(line, 50, programFile) != NULL) {
        parseLine(line, &label, &instruction);
        if (label != NULL) {
            //Check if it is a first line and we have a "start" symbol follwed by an integer
            if (firstLine) {
                if (strcmp(label, "start") == 0 && isInteger(instruction)) {
                    locctr += atoi(instruction);
                }
                firstLine = !firstLine;
            }
            insertNode(symbolTable, label, locctr);
        }

        locctr += computeLocCtr(label, instruction, instructionSet);
    }

    if (label) {
        free(label);
    }
    if (instruction) {
        free(instruction);
    }
    
}

int main(int args, char* argv[]) {
    if (args != 4) {
        fprintf(stderr, "Wrong number of parameters passed to program.");
        printf("\nUSAGE: firstpass programfile instructionset  hashtablesize");
        return -1;
    }
    FILE* instructionFile = fopen(argv[1], "r");
    FILE* programFile = fopen(argv[2], "r");
    if (instructionFile == NULL || programFile == NULL) {
        fprintf (stderr, "Unable to open instruction set file or program file");
        exit(1);
    }

    int size = atoi(argv[3]);
    /**
     * This hashTable is used to store list of instruction
     */
    BSTTree* instructionSet = parseInstructionSet(instructionFile, size);
    inorder(instructionSet);
    printf ("\n\nheight = %d\n\n", height(instructionSet));

    HashTable* symbolTable = newHashTable(size);
    assemblerPass(programFile, instructionSet, symbolTable);
    printHashTable(symbolTable);

    fclose(instructionFile);
    fclose(programFile);
    deleteHashTable(&symbolTable);
    deleteTree(&instructionSet);
    return 0;
}