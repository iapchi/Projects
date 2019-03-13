#ifndef UTILITY_H__
#define UTILITY_H__

#include "ctype.h"
#include <stdlib.h>

/**
 * Method to check if a string is integer or not
 */
int isInteger(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/**
 * Method to copy given length of a string from src to destination, allocates the memory if destination is null
 */
void copy(char** destination, char* src, int start_index, int length) {
    if (*destination != NULL) {
        free(*destination);
        *destination = NULL;
    }
    *destination = (char*) malloc(sizeof(char*) * (length + 1));
    int j = 0;
    int i;
    for (i = start_index; i < start_index + length; ++i) {
        (*destination)[j++] = src[i];
    }
    (*destination)[j] = 0;
}
#endif