#ifndef UTILITY_H__
#define UTILITY_H__
#include <ctype.h>

int isUpperCase(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!isupper(str[i])) {
            return 0;
        }
    }
    return 1;
}

int isInteger(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}
#endif