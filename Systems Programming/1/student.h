#ifndef __STUDENT_H__
#define __STUDENT_H__
#define MAX 255
#include <stdint.h>

/**
 * Stucture for student contains char firstname, char lastname, unsigned id, and float gpa
 */
typedef struct
{
    char firstname[MAX];
    char lastname[MAX];
    unsigned int id;
    float gpa;
} student;


#endif