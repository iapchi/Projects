#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int createFile(char* filePath);
int createDirectory(char* filePath);
int createLink(char* oldPath, char* linkPath, int type);
void printUsage();

int main(int argc, char** argv) {

    if (argc == 3) {
        // If there -f handle is provided then create a file
        if (strcmp(argv[1], "-f") == 0) {
            return createFile(argv[2]);
        }
        // If there -d handle is provided then create a directory
        else if (strcmp(argv[1], "-d") == 0) {
            return createDirectory(argv[2]);
        }
        // If invalid flag is provided, then show error
        else {
            printUsage();
        }
    }
    else if (argc == 4) {
        // If -h flag is provided create a hard link from args[2] to args[3]
        if (strcmp(argv[1], "-h") == 0) {
            return createLink(argv[2], argv[3], 0);
        }
        // If -h flag is provided create a soft link from args[2] to args[3]
        else if (strcmp(argv[1], "-s") == 0) {
            return createLink(argv[2], argv[3], 1);
        }
        // If invalid arguments, show error
        else {
            printUsage();
        }
    }
    // If invalid arguments, show error
    else {
        printUsage();
    }

    return 0;
}

// Function to create a file
int createFile(char* filePath) {
    // O_CREAT is used to open the file in create mode. To show error if file already exist, O_EXCL is used
    // 0640 is the file access permisssions
    int fd = open(filePath, O_CREAT | O_EXCL, 0640);

    // If file is opened succesfully, close it and return success
    if (fd != -1) {
        close(fd);
        return 0;
    }
    // File failed to open show error
    fprintf (stderr, "\nUnable to create file %s. Error Details: %s", filePath, strerror(errno));
    return -1;
}

// Function to create a directory
int createDirectory(char* dirPath) {
    // Create a directory with permissions 0750
    // If directory failed to create then show error
    if (mkdir(dirPath, 0750) == -1) {
        fprintf (stderr, "\nUnable to create directory %s. Error Details: %s", dirPath, strerror(errno));
        return -1;
    }
    return 0;
}

// Function to create a link from oldPath to linkPath. Type of link is decided by type paramter
// if type is 1 then symlink is created otherwise hard link is created
int createLink(char* oldPath, char* linkPath, int type) {
    if (type == 1) {
        // Create soft link
        if (symlink(oldPath, linkPath) == -1) {
            fprintf (stderr, "\nUnable to create link %s. Error Details: %s", linkPath, strerror(errno));
            return -1;
        }
    }
    else if (type == 0) {
        // Create hard link
        if (link(oldPath, linkPath) == -1) {
            fprintf (stderr, "\nUnable to create link %s. Error Details: %s", linkPath, strerror(errno));
            return -1;
        }
    }
    return 0;
}

void printUsage() {
    printf ("USAGE: create [-f|-d|-s|-h] path");
}