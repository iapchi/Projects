#include "conversion.h"
#include <errno.h>
#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/**
 * Function to convert binary file to text file
 */
int binaryToTextFile(char* inputFile, char* outputFile) {
    int success = 0, num_read, first = 1;
    student x;
    unsigned char fLength, lLength;
    FILE *input = NULL, *output = NULL;

    assert(inputFile != NULL && outputFile != NULL);

    /**
     * Open input file in reading binary mode
     */
    input = fopen(inputFile,"rb");
    if (input == NULL) {
        printf("ERROR: File cannot be opened%s\n", inputFile);
        return -1;
    }

    /**
     * Open input file in writing mode
     */
    output = fopen(outputFile,"w");
    if (output == NULL) {
        printf("ERROR: File cannot be opened%s\n", outputFile);
        fclose(input);
        return -1;
    }


    while (1) {
        /**
         * Check if we have rached file's end and breaks the loop
         */
        if (feof(input)) {
            break;
        }

        /**
         * Read from binary file.
         */
        fread(&fLength, 1, 1, input);
        fread(x.firstname, fLength, 1, input);
        x.firstname[fLength] = 0;
        fread(&lLength, 1, 1, input);
        fread(x.lastname, lLength, 1, input);
        x.lastname[lLength] = 0;
        fread(&x.id, sizeof(int), 1, input);
        fread(&x.gpa, sizeof(float), 1, input);

        /**
         * Check if we have rached file's end and breaks the loop
         */
        if (feof(input)) {
            break;
        }
        //Success tells us no. of records read successfully
        success++;
        if (!is_big_endian()) {
            unsigned char* c = (unsigned char*)&x.id;
            swap(c, c + 3);
            swap(c + 1, c + 2);
            c = (unsigned char*)&x.gpa;
            swap(c, c + 3);
            swap(c + 1, c + 2);
        }
        fprintf(output, "%s %s %u %.1f\n", x.firstname, x.lastname, x.id, x.gpa);
        //printf("%d %d %s %s %d %.1f\n", fLength, lLength, x.firstname, x.lastname, x.id, x.gpa);
    }
	//File closing
    fclose(input);
    fclose(output);
    return success;
}