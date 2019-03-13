    /**
      *Jacky Li
      *
      *
      */
#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"

//Function protoypes
unsigned int external_file_size(FILE* file);
char* read_file_info(FILE* archive, unsigned int* sz) ;
int contains(char** strings, int len, char* target);
int is_little_endian();

//For 4 bytes numbers only
void get_big_endian(void* x);
void swap(char* a, char* b);
int freadInt(int *ptr, size_t sz, int n, FILE* file);

int fwriteInt(int *ptr, size_t sz, int n, FILE* file) ;
#endif