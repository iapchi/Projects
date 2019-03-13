#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readfile.h"

//main method
int main(int argc, char* argv[]) {
    if (argc > 2) { //If incorrect number of arguments
        fprintf (stderr, "Invalid number of command line arguments.\nUsage: organizer [directorypath]");
	exit(1);
    }

    char* path = NULL;
    //if we have 1 argument, use current working directory as the folder, so copy '.' to path
    if (argc == 1) {
        path =  malloc(2);
        path[0] = '.', path[1] = 0;
    }
    //otherwise copy the user supplied folder
    else if (argc == 2) {
        int len = strlen(argv[1]);
        path = malloc(len + 1);
        strcpy(path, argv[1]);
    }

    readdirectory(path);
    free(path);

    return 0;
}