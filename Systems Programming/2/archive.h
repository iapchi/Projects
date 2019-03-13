    /**
      *Jacky Li
      *
      *
      */
#ifndef __ARCHIVE_H__
#define __ARCHIVE_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "archive.h"
#include "utility.h"
#include "def.h"

//fuction protoypes for archive and unarchive
void archive(char** filenames, int numFiles, char* archivename);
void unarchive(char* archivefile);
int store(FILE* ar, char* filename);
int retrieve(FILE* archive);

#endif