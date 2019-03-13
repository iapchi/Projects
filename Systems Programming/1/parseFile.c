#include "conversion.h"
#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

/**
 * Function to process binary file
 */
int printStats(char* inputFile) {
    int success = 0, num_read, first = 1;
    student x;
    unsigned char fLength, lLength;
    FILE *input = NULL;

    assert(inputFile != NULL);

    /**
     * Open input file in reading binary mode
     */
    input = fopen(inputFile,"rb");
    if (input == NULL) {
        printf("ERROR: File cannot be opened%s\n", inputFile);
        return -1;
    }

    student maxStudent, minStudent;
    maxStudent.id = 0;
    maxStudent.gpa = -1;
    minStudent.id = INT_MAX;
    minStudent.gpa = FLT_MAX;
    int maxLen = -1, minLen = INT_MAX;


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

        if (!is_big_endian()) {
            unsigned char* c = (unsigned char*)&x.id;
            swap(c, c + 3);
            swap(c + 1, c + 2);
            c = (unsigned char*)&x.gpa;
            swap(c, c + 3);
            swap(c + 1, c + 2);
        }

        int tLength = fLength + lLength + 2;
        if (tLength > maxLen) {
            maxLen = tLength;
            strcpy(maxStudent.firstname, x.firstname);
            strcpy(maxStudent.lastname, x.lastname);
        }

        if (tLength < minLen) {
            minLen = tLength;
            strcpy(minStudent.firstname, x.firstname);
            strcpy(minStudent.lastname, x.lastname);
        }

        if (x.gpa > maxStudent.gpa) {
            maxStudent.gpa = x.gpa;
        }
        if (x.gpa < minStudent.gpa) {
            minStudent.gpa = x.gpa;
        }

        if (x.id > maxStudent.id) {
            maxStudent.id = x.id;
        }
        if (x.id < minStudent.id) {
            minStudent.id = x.id;
        }
        //printf("%d %d %s %s %d %.1f\n", fLength, lLength, x.firstname, x.lastname, x.id, x.gpa);
    }

    fclose(input);
    printf("%s %s\n%s %s\n%u\n%u\n%.1f\n%.1f", maxStudent.firstname, maxStudent.lastname,
            minStudent.firstname, minStudent.lastname, maxStudent.id, minStudent.id,
            maxStudent.gpa, minStudent.gpa);
    fflush(stdout);
    return 0;
}