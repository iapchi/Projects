#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#ifndef _READFILE_H__
#define _READFILE_H__

void readdirectory(char* path);
void parsefile(char* filename, char* parent_dir);
int tokenizeFilename(char* filename, int* total, char* args[]);

int moveFile(char* filename, char* parent_dir, const char* dirname);

int checkDirectory(char* parent_dir, const char* dirname);
int moveAudioFile(char* filename, char** args, int len, char* parent_dir);
int moveTvSeries(char* filename, char** args, int len, char* parent_dir);
int moveMovieFile(char* filename, char** args, int len, char* parent_dir);
#endif