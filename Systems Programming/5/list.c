#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

void listAllNonHiddenFiles(char* path, int type);
char* concat(const char *s1, const char *s2);
void printUsage();

int main(int argc, char** argv) {
    // If there are no arguments, then list current directory
    if (argc == 1) {
        listAllNonHiddenFiles(".", 0);
    }
    else if (argc == 2) {
        // If -i is provided as argument then list files in long format
        if (strcmp(argv[1], "-i") == 0) {
            listAllNonHiddenFiles(".", 1);
        }
        // If -h is provided as argument then list hidden files
        else if (strcmp(argv[1], "-h") == 0) {
            listAllNonHiddenFiles(".", 2);
        }
        else {
            // Otherwise, argument is treated as a path
            listAllNonHiddenFiles(argv[1], 0);
        }
    }
    else if (argc == 3) {
        // If path and -i flag is provided then list files in long format in given path
        if (strcmp(argv[1], "-i") == 0) {
            listAllNonHiddenFiles(argv[2], 1);
        }
        // If path and -h flag is provided then list hidden files in given path
        else if (strcmp(argv[1], "-h") == 0) {
            listAllNonHiddenFiles(argv[2], 2);
        }
        else { // Invalid arguments, show error
            printUsage();
        }
    }
    else { // Invalid arguments, show error
        printUsage();
    }

    return 0;
}

// Function to read a directory. It lists in various formats based on type
// If type is 0 then each file is listed on new file
// If type is 1 then contents are listed in long format
// If type is 2 then hidden files are listed
void listAllNonHiddenFiles(char* path, int type) {
    DIR *dir;
    struct dirent *dp;
    struct stat fileStat;

    // Open the directory to read
    dir = opendir(path);

    // If path failed to open
    if (errno != 0) {
        fprintf (stderr, "Error occurred while opening directory \"%s\". Error details: %s", path, strerror(errno));
        return;
    }

    // If directory is opened
    if (dir) {
        // Iterate over the contents of the directory
        while ((dp = readdir(dir)) != NULL) {

            // List in default format
            if (type == 0) {
                // Print non hidden files, All hidden files start with '.'
                if (dp->d_name[0] != '.') {
                    printf("%s\n", dp->d_name);
                }
            }
            // List the files in long format
            else if (type == 1) {
                // Print non hidden files, All hidden files start with '.'
                if (dp->d_name[0] != '.') {
                    // Get the path to the file
                    char* filePath = concat(path, dp->d_name);
                    // Get the attributes of file, if failed to get then show error
                    if (stat(filePath, &fileStat) == -1) {
                        perror("error in stat");
                    }
                    else {
                        // Print the attributes of file
                        printf("\n%-10ld%-10lld  ", (long)fileStat.st_ino, (long long) fileStat.st_size);
                        printf((S_ISDIR(fileStat.st_mode))  ? "d" : "-");
                        printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
                        printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
                        printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
                        printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
                        printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
                        printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
                        printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
                        printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
                        printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
                        printf ("  %s", dp->d_name);
                    }
                    free(filePath);
                }
            }
            // List hidden files
            else if (type == 2) {
                if (dp->d_name[0] == '.') {
                    printf("%s\n", dp->d_name);
                }
            }
        }
        closedir(dir);
    }
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

void printUsage() {
    printf ("USAGE: list [-h|-i] path");
}