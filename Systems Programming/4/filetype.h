#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#ifndef _FILETYPE_H__
#define _FILETYPE_H__


/*Macro constants for different file types*/
#define AUDIO   0
#define VIDEO   1
#define WORD    2
#define TEXT    3
#define IMAGE   4
#define OTHER   5

char* getExtension(char* filename);
int getfiletype(char* filename);

#endif