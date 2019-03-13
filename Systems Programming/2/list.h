    /**
      *Jacky Li
      *
      *
      */
#ifndef __LIST_H__
#define __LIST_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "utility.h"
#include "def.h"
#include <math.h>

//function protoypes for vertify and list_details
void list_details(char* archivename);
int verify(char** filenames, int numFilesOrig, char* archivename);
void display_file_info(FILE* archive) ;
int checkFile(FILE* archive, char* filename) ;
#endif