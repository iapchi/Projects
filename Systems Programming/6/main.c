#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "opcodeTable.h"
#include "symbolTable.h"
#include "utility.h"
#define REG_LENGTH 9
#define AD_LENGTH 11

#define BUFFER_LENGTH 50

int isErrorPresent = 0;
char REG[][4] = { "A", "X", "L", "B", "S", "T", "F", "PC", "SW" };
int REG_CODE[] = { 0, 1, 2, 3, 4, 5, 6, 8, 9 };

char AD[][6] = { "start", "end", "equ", "org", "base", "ltorg", "resb", "resw", "byte", "nobase", "word" };


typedef struct ins {
    char label[11];
    char opcode[11];
    char operand1[11];
    char operand2[11];
} Instruction;


void toUpper(char* str);
int findRegister(char* str);
int findDirective(char* str);
BSTTree* parseInstructionSet(char* filename, int size) ;
Instruction* createNewInstruction(char* line) ;
int computeLocCtr(Instruction* ins,  BSTTree* instructionSet, int*);
void assemblerFirstPass(FILE* programFile, BSTTree* instructionSet, HashTable* symbolTable);
void assemblerSecondPass(FILE* programFile, BSTTree* instructionSet, HashTable* symbolTable, FILE* outputFile);
void getBinary(unsigned int code, char ch[], int len);
void printOutput(FILE* file, int line, int locctr, int opcode, int operand1Addr, int operand2Addr, int opcodeLength, const char* nixbpe);
int getMode(char* operand) ;

/*
 * This function is used to conver a given string to its uppercase
 */
void toUpper(char* str) {
    int i = 0;
    while (str[i] != 0) {
        str[i] = toupper(str[i]);
    }
}

/**
 * This function is used to check if a given string is a register or not. If it is a register
 * then it returns its index otherwise -1
 */
int findRegister(char* str) {
    int i;
    for (i = 0; i < REG_LENGTH; ++i) {
        if (strcmp(REG[i], str) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * This function is used to check if a given string is a assembler directive or not. If it is a register
 * then it returns its index otherwise -1
 */
int findDirective(char* str) {
    int i;
    for (i = 0; i < AD_LENGTH; ++i) {
        // AD is the global array containing assembler directives
        if (strcmp(AD[i], str) == 0) {
            return i;
        }
    }
    return -1;

}

/*
 * Method to parse opcode file and insert sybmols into binary tree
 */
BSTTree* parseInstructionSet(char* filename, int size) {
    FILE* instructionFile = fopen(filename, "r");
    if (instructionFile == NULL) {
        fprintf (stderr, "\nUnable to open instruction set file\n");
        return NULL;
        exit(1);
    }

    char instruction[6];
    int opcode, format;
    BSTTree* tree = newTree(size);

    while (fscanf(instructionFile, "%6s%d%d", instruction, &opcode, &format) == 3) {
        insert(tree, instruction,  opcode, format);
    }
    fclose(instructionFile);
    return tree;
}

/*
 * Function to create a new instruction
 */
Instruction* createNewInstruction(char* line) {
    int i, j;
    Instruction* ins = (Instruction*)calloc(1, sizeof(Instruction));

    // Initialize label
    if (line[0] == '\t') {
        ins->label[0] = 0;
    }
    else {
        j = 0;
        while (line[i] != 0 && !isspace(line[i])) {
            ins->label[j++] = line[i++];
        }
        ins->label[j] = 0;
    }

    // Initialize opcode
    i++;
    j = 0;
    while (line[i] != 0 && !isspace(line[i])) {
        ins->opcode[j++] = line[i++];
    }
    ins->opcode[j] = 0;

    // Initialize operand1
    if (line[i] != 0)
        i++;
    j = 0;
    while (line[i] != 0 && !isspace(line[i])) {
        ins->operand1[j++] = line[i++];
    }
    ins->operand1[j++] = 0;

    // Initialize operand2
    if (line[i] != 0)
    i++;
    j = 0;
    while (line[i] != 0 && !isspace(line[i])) {
        ins->operand2[j++] = line[i++];
    }
    ins->operand2[j++] = 0;

    return ins;
}



/*
 * Computes and location value for a given symbol
 */
int computeLocCtr(Instruction* ins,  BSTTree* instructionSet, int *opcodeLength) {
    int found = 0, locctr = 0;
    int val = getFormat(instructionSet, ins->opcode, &found);
    if (!found) {
        val = 1;
    }

    if(strcmp(ins->opcode, AD[10]) == 0) {  //If opcode is WORD
        locctr += 3;
    }
    else if (strcmp(ins->opcode, AD[7]) == 0)  { //If opcode is RESW
        locctr += 3 * atoi(ins->operand1);
    }
    else if(strcmp(ins->opcode, AD[6]) == 0) {   //If opcode is RESB
        locctr += atoi(ins->operand1);
    }
    else if(found) {
        locctr += val;
    }
    else if (!found) {
        isErrorPresent = 1;
    }

    *opcodeLength = val;
    return locctr;
}


/**
 * This method performs first pass of assembler
 */
void assemblerFirstPass(FILE* programFile, BSTTree* instructionSet, HashTable* symbolTable) {
    int locctr = 0, t = 0;
    int len;
    char buffer[BUFFER_LENGTH];

    while (fgets(buffer, BUFFER_LENGTH, programFile) != NULL && isErrorPresent == 0) {
        // Remove whitespace from the end of buffer
        len = strlen(buffer);
        if (isspace(buffer[len - 1])) {
            buffer[len - 1] = 0;
        }

        // Parse line
        Instruction* ins = createNewInstruction(buffer);
        if (strcmp(ins->opcode, AD[0]) == 0) { // If start directive
            if (ins->operand1[0] != 0)
                locctr = atoi(ins->operand1);
        }
        else if (strcmp(ins->opcode, AD[1]) == 0) {   //If end directive
            free(ins);
            return;
        }
        else  {
            if (ins->label[0] != 0) {
                Node* node = getNode(symbolTable, ins->label);
                if(node == NULL) { // Check if this label is present in symbol table
                    insertNode(symbolTable, ins->label, locctr);
                }
                else {  // Duplicate label
                    isErrorPresent = 1;
                }
            }
            locctr += computeLocCtr(ins, instructionSet, &t);
        }

        free(ins);
    }
}



/**
 * This method performs second pass of assembler
 */
void assemblerSecondPass(FILE* programFile, BSTTree* instructionSet, HashTable* symbolTable, FILE* outputFile) {
    int locctr = 0;
    int len;
    char buffer[BUFFER_LENGTH];
    int line = 0;
    int addr1;
    int addr2;
    int opcodeLength;
    int ind;

    while (fgets(buffer, BUFFER_LENGTH, programFile) != NULL && isErrorPresent == 0) {
        line++;
        addr1 = addr2 = opcodeLength = ind = -1;
        // Remove whitespace from the end of buffer
        len = strlen(buffer);
        if (isspace(buffer[len - 1])) {
            buffer[len - 1] = 0;
        }

        // Parse line
        Instruction* ins = createNewInstruction(buffer);
        if (strcmp(ins->opcode, AD[0]) == 0) { // If start directive
            if (ins->operand1[0] != 0)
                locctr = atoi(ins->operand1);
        }
        else if (strcmp(ins->opcode, AD[1]) == 0) {   //If end directive
            free(ins);
            return;
        }
        else if ((ind = findDirective(ins->opcode)) != -1) {
            int t, l;
            l = computeLocCtr(ins, instructionSet, &t);
            if (ind == 10) {// if opcode is word
                char ch[25]; //3 bits so length is 24 + 1, 1 is used for null character
                getBinary(atoi(ins->operand1), ch, 24);
                fprintf(outputFile, "%d %d %s\n", line, locctr, ch);
            }
            locctr += l;
        }
        else if (ins->label[0] != 0 && ins->opcode[0] == 0  && ins->operand1[0] == 0 && ins->operand2[0] == 0) {
            // if only label is present
            // do nothing
        }
        else if (ins->label[0] == 0 && ins->opcode[0] != 0 && ins->operand1[0] == 0 && ins->operand2[0] == 0) {
            // instruction contains opcode only
            int op = getOpCode(instructionSet, ins->opcode);
            int l = computeLocCtr(ins, instructionSet, &opcodeLength);
            // It outputs only opcode, since addr = addr2 = -1 and opcodeLength will be 1
            printOutput(outputFile, line, locctr, op, addr1, addr2, opcodeLength, "");
            locctr += l;
        }
        else {// instruction contains opcode and operand
            int op = getOpCode(instructionSet, ins->opcode), index;
            int l =  computeLocCtr(ins, instructionSet, &opcodeLength);
            int mode = 0;
            // If operand1 is present
            if (ins->operand1[0] != 0) {
                mode = getMode(ins->operand1);
                if ((index = findRegister(ins->operand1)) != -1) { // If operand is register, address will be the register code
                    addr1 = REG_CODE[index];
                }
                else { // Search in symbol table
                    Node* node = getNode(symbolTable, ins->operand1);
                    if(node == NULL) { // If label is absent, show error
                        isErrorPresent = 1;
                        printf ("\nError produced by: %s %s %s", ins->opcode, ins->operand1, ins->operand2);
                    }
                    else {  // Fetch the address
                        addr1 = node->lcValue;
                    }
                }
            }

            if (ins->operand2[0] != 0) {
                mode = getMode(ins->operand2);
                if ((index = findRegister(ins->operand2)) != -1) {
                    addr2 = REG_CODE[index];
                }
                else {
                    // Search in symbol table
                    Node* node = getNode(symbolTable, ins->operand2);
                    if(node == NULL) { // Check if this label is present in symbol table
                        isErrorPresent = 1;

                    }
                    else {  // Duplicate label
                        addr2 = node->lcValue;
                    }
                }
            }
            char str[7] = "";
            if (opcodeLength == 3) {
                if (mode == 1) { //Indirect addressing
                    strcpy(str, "100000");
                }
                else if (mode == 2) {
                    strcpy(str, "010000");
                }
                else {
                    strcpy(str, "000000");
                }
            }
            printOutput(outputFile, line, locctr, op, addr1, addr2, opcodeLength, str);
            locctr += l;
        }

        free(ins);
    }
}

/**
 * This function is used to check the mode from the given operand
 */
int getMode(char* operand) {
    int mode = 0, i;
    if (operand[0] == '@') { // Indirect addressing mode
        mode = 1;
    }
    else if (operand[0] == '#') {   //Immediate addressing mode
        mode = 2;
    }

    if (operand[0] == '@' || operand[0] == '#') {
        i = 1;
        // shift operand towards left
        while (operand[i]) {
            operand[i - 1] = operand[i];
            i++;
        }
        operand[i - 1] = 0;
    }
    return mode;
}

/**
 * This function saves the binary of given integer "code" into the character array ch
 * It only saves only the first len bytes only
 */
void getBinary(unsigned int code, char ch[], int len) {
    int i = 0;
    if ((int)code == -1) {
        ch[0] = 0;
        return;
    }

    // Iterate over the bits of code and save it in ch
    while (i < len) {
        // Get ith bit of code, Adding 0 converts 0 and 1 to ASCII 48 and 49 which are characters '0' and '1'
        ch[len - i - 1] =  ((code & ( 1 << i )) >> i) + '0';
        i++;
    }
    ch[i] = 0;
}

/**
 * This function is used to write the output to the output file in many cases
 * If operand is -1 then empty string is written
 * It converts the opcode into the binary using getBinary function and outputs it into the
 * output file
 */
void printOutput(FILE* file, int line, int locctr, int opcode, int operand1Addr, int operand2Addr, int opcodeLength, const char* nixbpe) {
    fprintf (file, "%d %d ", line, locctr);
    if (opcodeLength == 1) { // If opcode is of length 1
        char ch[9];
        // save the binary code in ch
        getBinary(opcode, ch, 8);
        fprintf(file, "%s\n", ch);
    }
    else if (opcodeLength == 3) { // // If opcode is of length 3
        char ch1[9], ch2[13];
        getBinary(opcode, ch1, 6);
        getBinary(operand1Addr, ch2, 12);
        fprintf(file, "%s %s %s\n", ch1, nixbpe, ch2);
    }
    else if (opcodeLength == 2) { // If opcode is of length 1
        char ch1[9], ch2[5], ch3[5];
        getBinary(opcode, ch1, 8);          // Opcode is of length 8
        getBinary(operand1Addr, ch2, 4);    // Operands are of length 4
        getBinary(operand2Addr, ch3, 4);
        fprintf(file, "%s %s %s\n", ch1, ch2, ch3);
    }
    else { // Unsupported
        isErrorPresent = 1;
    }
}


int main(int args, char* argv[]) {
    if (args != 4) {
        fprintf(stderr, "\nWrong number of parameters passed to program.");
        printf("\nUSAGE: sicxe instructionset programfile hashtablesize\n");
        return -1;
        exit(1);
    }
    FILE* instructionFile = fopen(argv[1], "r");
    FILE* programFile = fopen(argv[2], "r");
    if (instructionFile == NULL || programFile == NULL) {
        fprintf (stderr, "\nUnable to open instruction set file or program file\n");
        exit(1);
    }
    /**
     * Error if programfile is not asm
     */
    int size = atoi(argv[3]);
    int l = strlen(argv[2]);
    char* outputFileName = (char*) calloc(l + 4, sizeof(char*));    
    strcpy(outputFileName, argv[2]);
    while (l > 0 && outputFileName[l] != '.') l--;
    if (strcmp(outputFileName + l, ".asm") != 0) {
        fprintf (stderr, "\nProgramfile should be in .asm format\n");
        return -1;
        exit(1);
    }
    outputFileName[l] = 0;
    strcat(outputFileName, ".obj");

    /**
     * This hashTable is used to store list of instructions
     */
    BSTTree* instructionSet = parseInstructionSet(argv[1], size);
    printf ("\nInorder Traversal is: \n");
    inorder(instructionSet);

    printf ("\nHeight = %d", treeHight(instructionSet));
    HashTable* symbolTable = newHashTable(size);
    assemblerFirstPass(programFile, instructionSet, symbolTable);

    printf("\n\nHashTable is:\n");
    printHashTable(symbolTable);

    fseek(programFile, 0, SEEK_SET);
    char ch[25];
    if (!isErrorPresent) {
        int l = strlen(argv[2]);
        char* outputFileName = (char*) calloc(l + 4, sizeof(char*));
        strcpy(outputFileName, argv[2]);
        while (l > 0 && outputFileName[l] != '.') l--;
        outputFileName[l] = 0;
        strcat(outputFileName, ".obj");
        FILE* outputFile = fopen(outputFileName, "w");
        assemblerSecondPass(programFile, instructionSet, symbolTable, outputFile);
        free(outputFileName);
        printf("\nObj file created\n");
    }

    deleteHashTable(&symbolTable);
    deleteTree(&instructionSet);
    return 0;
}