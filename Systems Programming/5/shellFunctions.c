#include "shellFunctions.h"

// Function to get working directory
char* getWorkingDirectory() {
    char* pwd = NULL;
    int bufsize = BUFFER_SIZE;

    // Allocate memory to store the pwd
    pwd = (char*) malloc(sizeof(char) * bufsize);
    // If failed to allocate
    if (pwd == NULL) {
        fprintf (stderr, "Unable to allocate memory.");
        return NULL;
    }

    while (1) {
        // Get the working directory
        pwd = getcwd(pwd, bufsize);

        // If got error buffer overflow then double the size of buffer and try again
        if (errno == ERANGE) {
            pwd = realloc(pwd, 2 * bufsize);
            bufsize = bufsize * 2;
        }
        else { // Else break out of loop
            break;
        }
    }

    // Working directory is still NULL then show error
    if (pwd == NULL) {
        fprintf (stderr, "Error occurred while getting present working directory Error details: %s", strerror(errno));
    }

    // Return present workind directory
    return pwd;
}


int executeWdCommand() {
    char* pwd = getWorkingDirectory();
    if (pwd == NULL) {
        return EXIT_FAILURE;
    }
    free(pwd);
    return EXIT_SUCCESS;
}

int executeChwdCommand(char* cmd, char** args, int numArgs) {
    // If invalid arguments are passed then show error
        if (numArgs != 2) {
            printf ("USAGE: chwd path");
        }
        else{
            char* path = NULL;
            // If relative path is specified, then change the working directory to given path
            if (args[1][0] != '/') {
                char* pwd = getWorkingDirectory();
                if (pwd == NULL) {
                    return EXIT_FAILURE;
                }

                // Find and store the absolute path in path.
                path = (char*)malloc(strlen(pwd) + 2 + strlen(args[1]));
                // Copy current present working directory
                strcpy(path, pwd);

                // Copy '/'
                strcat(path, "/");

                // Copy the relative path
                strcat(path, args[1]);
                free(pwd);
            }
            else {
                // If absolute path is specified, then change the working directory to given path, so
                // simply copy the arguments in the path
                path = (char*)malloc(strlen(args[1]) + 1);
                strcpy(path, args[1]);
            }

            // Try to change the directory, if failed then show error
            if (chdir(args[1]) == -1) {
                fprintf (stderr, "An error occurred while changing working directory: %s", args[1]);
                free (path);
                return EXIT_FAILURE;
            }
            // Free the memory allocated to path
            free(path);
        }
        return EXIT_SUCCESS;
}