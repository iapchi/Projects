#ifndef _SHELL_FUNCTIONS_H
#define _SHELL_FUNCTIONS_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ctype.h>

char* getWorkingDirectory();
int executeWdCommand();
int executeChwdCommand(char* cmd, char** args, int numArgs) ;

#endif