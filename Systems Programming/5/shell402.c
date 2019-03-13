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
#include "shellFunctions.h"
#define BUFFER_SIZE 1024

void printUsage();
int readCommands();
int readCommandsFromFile(FILE* file);
int printPrompt();
char *readLine(void);
char** parseCommand(const char* line, char** cmd, int* numArgs) ;
int execute(char* cmd, char** args, int num) ;
int isBuiltInCommand(char* cmd);
int executeBuiltInCommand(char* cmd, char** args, int num);
int executeCommand(char* cmd, char** args, int num);
char* concat(const char *s1, const char *s2);


char baseDir[] = "", listDir[] = "./list", createDir[] = "./create";

int main(int argc, char* argv[]) {
    int exitStatus = EXIT_SUCCESS;

    //getWorkingDirectory();
    //concat(baseDir, "./list");
    //concat(baseDir, "./create");

    // If no file is provided to shell read commands from stdin
    if (argc == 1) {
        exitStatus = readCommands();
    }
    else if (argc == 2) {
        // If file is provided then read commands from the file
        FILE* file = fopen(argv[1], "r");

        // If file failed to open then show error
        if (file == NULL) {
            fprintf (stderr, "Unable to open script %s", argv[1]);
            return EXIT_FAILURE;
        }
        exitStatus = readCommandsFromFile(file);
        fclose(file);
    }
    // Invalid arguments passed
    else {
        printUsage();
    }

    return exitStatus;
}

//Function to concatenate two string separated by '/'
char* concat(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result;
    if (s1[len1 - 1] == '/') {
        result = malloc(len1 + len2 + 1);
        strcpy(result, s1);
        strcat(result, s2);
    }
    else {
        result = malloc(len1 + len2 + 2);
        strcpy(result, s1);
        strcat(result, "/");
        strcat(result, s2);
    }

    return result;
}

// Funtion to print usage
void printUsage() {
    printf ("shell402 [path]\n\tPath is the file path of the script file.");
}


// Function to check if string is empty or not
int isEmpty(const char* temp) {
    if (temp == NULL)
        return 1;
    int len = strlen(temp), n = 0;
    for (int i = 0; i < len; ++i) {
        if (isspace(temp[i]))
            n++;
    }
    if (n == len) return 1;
    return 0;
}
// Function to remove spaces before and after the string
char* trim(char* str) {
    int len = strlen(str), k = 0;
    for (int i = 0; i < len; ++i) {
        if (!isspace(str[i])) {
            k = i;
            break;
        }
    }
    for (int i = len - 1; i >= 0; --i) {
        if (isspace(str[i])) {
            str[i] = 0;
        }
        else {
            break;
        }
    }
    return str + k;
}

// read commands from the given file
int readCommands() {
    int retStatus = EXIT_SUCCESS;
    // While there are commands available
    while (retStatus == EXIT_SUCCESS && !feof(stdin)) {
        int numArgs = 0;
        char* line = NULL, **args = NULL, *cmd = NULL;

        // Print the prompt
        retStatus |= printPrompt();

        // Read a line
        line = readLine();
        // If line is invalid, then loop again
        if (strlen(line) == 0 || (strlen(line) == 1 &&(line[0] == '\n' || line[0] == '\r' || line[0] == ' ')) || strlen(trim(line)) == 0) {
            free(line);
            continue;
        }

        // Parse the line into comand and its arguments
        args = parseCommand(line, &cmd, &numArgs);

        // Execute the command
        retStatus |= execute(cmd, args, numArgs);

        // Free the resources
        if (cmd)
            free(cmd);
        if (args)
            free(args);
        if (line)
            free(line);
    }
}

// read commands from the given file
int readCommandsFromFile(FILE* file) {
    int retStatus = EXIT_SUCCESS;
    size_t len = 0;
    ssize_t read;
    char *line = NULL;

    // While there are lines in a file
    while ((read = getline(&line, &len, file)) != -1) {
        int numArgs = 0;
        char **args = NULL, *cmd = NULL, len = strlen(line);

        // If line is empty then skip this iteration
        if (len == 0 || (len == 1 &&(line[0] == '\n' || line[0] == '\r' || line[0] == ' ')) || strlen(trim(line)) == 0) {
            continue;
        }
        else { // Replace trailing '\n' if it exists
            if (line[len - 1] == '\n') {
                line[len - 1] = 0;
            }
        }

        // Parse the line to give command and arguments
        args = parseCommand(line, &cmd, &numArgs);

        // Execute the command
        retStatus |= execute(cmd, args, numArgs);

        // Free the resources
        if (cmd)
            free(cmd);
        if (args)
            free(args);
    }
    if (line)
        free(line);
     return (EXIT_SUCCESS);
}


// This function is used to print prompt
int printPrompt() {
    // Get the working directory and print it as the prompty
    char* pwd = getWorkingDirectory();
    // If pwd is NULL, that means we failed to get the present working director so return failure
    if (pwd == NULL) {
        return EXIT_FAILURE;
    }

    // Print the present working directory
    printf ("%s $ ", pwd);

    // Free the memory
    free(pwd);
    return EXIT_SUCCESS;
}



// Method to read a line from the stdin
char *readLine(void)
{
    int position = 0;
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    int c;
    int bufsize = BUFFER_SIZE;

    // If memory is not allocated to buffer then exit with failure
    if (!buffer) {
        fprintf(stderr, "Unable to allocate memory for buffer.\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read a character
        c = getchar();

        // If we hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // If we have exceeded the buffer, reallocate.
        if (position >= bufsize) {
            bufsize += BUFFER_SIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "Unable to allocate memory for buffer.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

// This function is used to check if line starts with a given prefix
int startsWith(const char* line, const char* prefix) {
    int len  = strlen(prefix);
    for (int i = 0; i < len; ++i) {
        if (prefix[i] != line[i]) {
            return 0;
        }
    }
    return 1;
}

char** parseCommand(const char* line, char** cmd, int* numArgs) {
    char* lineCopy = NULL;

    // If command is list, then replace it with ./list
    if (startsWith(line, "list")) {
        // Allocate memory
        lineCopy =(char*) malloc(sizeof(char) * (strlen(listDir) + strlen(line + 4) + 1)); //Extra 1 for null character

        // Copy ./line into line copy
        strcpy(lineCopy, listDir);

        // Copy the arguments
        strcat(lineCopy, line + 4);
    }
    // If command is create, then replace it with ./create
    else if (startsWith(line, "create")) {
        // Allocate memory
        lineCopy = (char*)malloc(sizeof(char) * (strlen(createDir) + strlen(line + 6) + 1)); //Extra 1 for null character
        // Copy ./create into line copy
        strcpy(lineCopy, createDir);
        // Copy the arguments
        strcat(lineCopy, line + 6);
    }
    else {
        // Create a copy of the line
        lineCopy = strdup(line);
    }

    // Parse the arguments
    char** args = NULL, *temp = NULL;
    // Split at " " and save first term in cmd
    *cmd = strtok(lineCopy, " ");
    temp = *cmd;

    // Also, save the command as the first argument
    *numArgs = 1;    // Length of argumetns
    args = (char**)malloc(sizeof(char**)); // First argument is command itself
    *args = trim(*cmd);

    // If there more terms
    while (temp != NULL) {
        // Split the remaining string at " "
        temp = strtok(NULL, " ");

        if (temp != NULL && !isEmpty(temp)) {
            // Reallocate the args to store the new argument
            (*numArgs)++;
            args = (char**)realloc(args, (*numArgs) * sizeof(char**));

            // Save it in arguments after trimming whitespaces
            args[(*numArgs) - 1] = trim(temp);
        }
    }

    return args;
}

// Method to execute the command with given arguments
int execute(char* cmd, char** args, int numArgs) {
    pid_t childPid, wpid;
    int status;

    // If is built in command
    if (isBuiltInCommand(cmd)) {
        // Execute built in command
        return executeBuiltInCommand(cmd, args, numArgs);
    }
    else {
        // Otherwise fork the process and execute the command
        childPid = fork();
        if (childPid == 0) {    //Child process
            exit(executeCommand(cmd, args, numArgs)); //calls execvp
        } else if (childPid < 0) { // Failed to fork
            perror ("Failed to create a child process. Exiting.");
            return -1;
        }
        else {   // Parent process, wait for child to terminate
             do {
              wpid = waitpid(childPid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return EXIT_SUCCESS;
}


// Method to check if cmd is build in command or not. Built in commands are those for which no forking is required
int isBuiltInCommand(char* cmd) {
    if (strcmp(cmd, "wd") == 0 || strcmp("chwd", cmd) == 0 || strcmp(cmd, "quit") == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to execute a built in command
int executeBuiltInCommand(char* cmd, char** args, int numArgs) {
    // If command was quit
    if (strcmp(cmd, "quit") == 0) {
        printf ("good bye");
        exit(0);
    }
    // If command is wd then print the working directory
    else if (strcmp(cmd, "wd") == 0) {
        return executeWdCommand();
    }
    //If command is chwd then chaange the working directory
    else if (strcmp(cmd, "chwd") == 0) {
        return executeChwdCommand(cmd, args, numArgs);
    }
}

// Function to execute the command which is not built in command like cat, echo, list and create
int executeCommand(char* cmd, char** args, int numArgs) {
    if (execvp(cmd, args) < 0) {
        fprintf(stderr, " Command %s execution failed. %s ", cmd, strerror(errno));
        free(cmd);
        return EXIT_FAILURE;
    }

    // Will never reach here
    return EXIT_SUCCESS;
}