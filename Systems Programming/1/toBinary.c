#include "conversion.h"
#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/**
 * Function to convert text file to binary file
 */
int textToBinaryFile(char* inputFile, char* outputFile) {
    int success = 0, num_read;
    student x;
    unsigned char fLength, lLength;
    FILE *input = NULL, *output = NULL;

    /*Check if correct arguments are passed to function*/
    assert(inputFile != NULL && outputFile != NULL);

    /**
     * Open input file in reading mode
     */
    input = fopen(inputFile,"r");
    if (input == NULL) {
        printf("ERROR: File cannot be opened%s\n", inputFile);
        return -1;
    }

    /**
     * Open output file in writing binary mode
     */
    output = fopen(outputFile,"wb");
    if (output == NULL) {
        printf("ERROR: File cannot be opened%s\n", outputFile);
        fclose(input);
        return -1;
    }


    while (1) {
        char ch;
        /**
         * Check if we have rached file's end and breaks the loop
         */
        if (feof(input)) {
            break;
        }

        /**
         * Read from text file. Each item is separated by a space
         */
        num_read = fscanf(input, "%s %s %u %f\n", x.firstname, x.lastname, &x.id, &x.gpa);
        //printf("Read: %s %s %u %.1f\n", x.firstname, x.lastname, x.id, x.gpa);

        //Success tells us no. of records read successfully
        success++;

        fLength = strlen(x.firstname);
        lLength = strlen(x.lastname);
        fwrite(&fLength, 1, 1, output);
        fwrite(x.firstname, 1, fLength, output);
        fwrite(&lLength, 1, 1, output);
        fwrite(x.lastname, 1, lLength, output);

        /**
         * If system is little endian
         * then convert reverse individual bytes of multibyte data
         */
        if (!is_big_endian()) {
            /**
             * Reversing individual bytes of id
             */
            unsigned char* c = (unsigned char*)&x.id;
            swap(c, c + 3);
            swap(c + 1, c + 2);

            /**
             * Reversing individual bytes of gpa
             */
            c = (unsigned char*)&x.gpa;
            swap(c, c + 3);
            swap(c + 1, c + 2);
        }
        fwrite(&x.id, 4, 1, output);
        fwrite(&x.gpa, 4, 1, output);
    }
	//File closing
    fclose(input);
    fclose(output);
    return success;
}