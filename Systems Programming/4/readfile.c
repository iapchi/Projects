#include "readfile.h"
#include "filetype.h"
#include "def.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char* concat(const char *s1, const char *s2);
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

/*
 * Function to read a directory
 */
void readdirectory(char* path) {
    DIR *dir;
    struct dirent *dp;
    struct stat sp;
    int rval;

    dir = opendir(path); //Open the directory
    if (0 != errno) {
        fprintf (stderr, "Error occurred while reading input directory \"%s\". Error details: %s", path, strerror(errno));
        return;
        exit(1);
    }

    rval = access (path, W_OK);
    if (rval != 0) {
        fprintf (stderr, "Cannot create directories in input directory %s. Error details: %s", path, strerror(errno));
        return;
        exit(1);
    }

    while ((dp=readdir(dir)) != NULL) { //If dp points to null, that is after last file in directory then break

        //If dp does not points to parent, self or folder then parse the file
        if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")) {
            char* temp = concat(path, dp->d_name);
            if (is_regular_file(temp)) {
                LOG ("Parsing file: %s", dp->d_name);
                parsefile(dp->d_name, path);
            }
            free(temp);
        }
    }

    closedir(dir);      //Close the directory
}

/**
 * This method parses the filenames and move them to thier respective folder
 */
void parsefile(char* filename, char* parent_dir) {
    int filetype = getfiletype(filename);       //Get file type

    if (filetype == AUDIO) {                    //If file type is audio

        int l = strlen(filename) + 2, len = 3;  //Len specifies the expected number of splits
        char* temp = malloc(l  * sizeof(char));
        char* args[3];                          //It stores the pointers to the different parts of the name
        strcpy(temp, filename);                 //Store a copy of filename, since strtok modifies the argument

        //split the filename into tokens wiht '-' as delimiter, if we have more than len (expected) splits
        //then tokenizeFilename returns -1. In such case audio filename is not according to given format.
        if (tokenizeFilename(temp, &len, args) == -1) {
            fprintf (stderr, "\nInvalid audio filename. Audio filename is not according to given format.");
            exit(1);
        } else {
            moveAudioFile(filename, args, len, parent_dir); //Move the file
        }
        free(temp);
    }
    else if (filetype == VIDEO) {               //If file type is video
        int l = strlen(filename) + 5, len = 4;  //Len specifies the expected number of splits
        char* temp = malloc(l  * sizeof(char));
        char* args[4];
        strcpy(temp, filename);                 //Store a copy of filename, since strtok modifies the argument


        if (tokenizeFilename(temp, &len, args) == -1) {  //If splits are more than len (expected) splits show error
            fprintf (stderr, "\nInvalid audio filename. Audio filename is not according to given format.");
            exit(1);
        }
        else if (len == 2) {                    //If there are 2 splits, then it is a movie file, so move movie file
            moveMovieFile(filename, args, len, parent_dir);
        }
        else if (len == 4) {                    //If there are 4 splits, then it is a tv series, so move tv series
            moveTvSeries(filename, args, len, parent_dir);
        }
        free(temp);
    }
    else if (filetype == TEXT || filetype == WORD) {    //If file is a document, move file with "documents" as a base folder
        moveFile(filename, parent_dir, "documents");
    }
    else if (filetype == IMAGE) {                       //If file is a image, move file with "image" as a base folder
        moveFile(filename, parent_dir, "pictures");
    }
    else {                                             //If file is a other, move file with "other" as a base folder
        LOG("Moving file: %s to other directory", filename);
        moveFile(filename, parent_dir, "other");
    }
}

/*
 * This function is used to concat two string with '/' as the joiner
 */
char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1)+strlen(s2)+2); //+1 for the zero-terminator

    strcpy(result, s1);         //Copy first string
    int len = strlen(s1);
    if (s1[len - 1] != '/') {   //Check if previous string ends with / so as to avoid two consecutive /
        strcat(result, "/");    //Copy '/' if previous string does not end with /
    }
    strcat(result, s2);         //Copy second string
    return result;
}

//artist-album-song.mp3
/*
 * Function to move a audio file in a parent directory
 */
int moveAudioFile(char* filename, char** args, int len, char* parent_dir) {
    char dirname[] = "music";                       //Name of the base folder
    char* source = concat(parent_dir, filename);    //Name of the source file, like ./file or dir/file
    if (checkDirectory(parent_dir, dirname)) {      //Check and create dirname within parent_dir. It will create, parent_dir/music
        char* temp = concat(parent_dir, dirname);
        if (checkDirectory(temp, args[0])) {        //check and create artist directory within the music directory
            char* artist = concat(temp, args[0]);
            if (checkDirectory(artist, args[1])) {  //check and create album directory within the artist directory
                char* album = concat(artist, args[1]);
                char* song = concat(album, args[2]);//Final name of the file
                errno = 0;
                LOG("Renaming file %s to %s", source, song);
                if (rename(source, song) == -1) {   //Move the file to destinaion directory
                    fprintf (stderr, "\nUnable to move file \"%s\" to \"%s\". Error Details: %s", source, song, strerror(errno));
                    exit(1);
                }
                free(album);
                free(song);
                free(artist);
                free(temp);
                free(source);
            }
        }
    }
    return -1;
}

//artist-album-song.mp3
//year-title.mkv
int moveMovieFile(char* filename, char** args, int len, char* parent_dir) {
    char dirname[] = "movies";                      //Name of the base directory for movies
    char* source = concat(parent_dir, filename);
    if (checkDirectory(parent_dir, dirname)) {      //Check and create movies directory within the parent directory
        char* temp = concat(parent_dir, dirname);
        if (checkDirectory(temp, args[0])) {        //check and create year directory
            char* year = concat(temp, args[0]);
            char* title = concat(year, args[1]);    //Name of the file
            errno = 0;
            LOG("Renaming file %s to %s", source, title);
            if (rename(source, title) == -1) {      //Move the file
                fprintf (stderr, "\nUnable to move file \"%s\" to \"%s\". Error Details: %s", source, title, strerror(errno));
                exit(1);
            }
            free(year);
            free(title);
            free(temp);
            free(source);
        }
    }
    return -1;
}


//show-season-episode-title.mkv
/**
 * This function moves the tv series file with name filename to a directory shows/season/ within the given parent directory
 */
int moveTvSeries(char* filename, char** args, int len, char* parent_dir) {
    char dirname[] = "shows";                       //Name of the base directory for tv shows
    char* source = concat(parent_dir, filename);
    if (checkDirectory(parent_dir, dirname)) {      //Check and create shows directory within the parent directory
        char* temp = concat(parent_dir, dirname);
        if (checkDirectory(temp, args[0])) {        //check and create shows/show-name directory
            char* show = concat(temp, args[0]);
            if (checkDirectory(show, args[1])) {    //check and create season directory
                char* season = concat(show, args[1]);

                //Concatenate episode and title with - as delimeter
                char *episode_title = malloc(strlen(args[2])+strlen(args[3])+2); //+1 for the zero-terminator
                strcpy(episode_title, args[2]);
                strcat(episode_title, "-");
                strcat(episode_title, args[3]);

                char* title = concat(season, episode_title);     //Name of the file in the destination directory
                errno = 0;
                LOG("Renaming file %s to %s", source, title);
                if (rename(source, title) == -1) {              //Move the file
                    fprintf (stderr, "\nUnable to move file \"%s\" to \"%s\". Error Details: %s", source, title, strerror(errno));
                    exit(1);
                }
                free(title);
                free(episode_title);
                free(season);
                free(show);
                free(temp);
                free(source);
            }
        }
    }
    return -1;
}

/**
 * This function moves the given file with name filename in parent_dir to a directory named dirname in parent_directory
 */
int moveFile(char* filename, char* parent_dir, const char* dirname) {

    if (checkDirectory(parent_dir, dirname)) {          //Check if dirname directory exists in parent_directory, otherwise create it
        char* temp = concat(parent_dir, dirname);
        char* destination = concat(temp, filename);     //Destination file path
        char* source = concat(parent_dir, filename);    //Source file path
        errno = 0;
        LOG("Renaming file %s to %s", source, destination);
        if (rename(source, destination) == -1) {        //Move the file, show error if failed to move
            fprintf (stderr, "\nUnable to move file \"%s\" to \"%s\". Error Details: %s", source, destination, strerror(errno));
            exit(1);
        }
        free(temp);
        free(source);
        free(destination);
        return 1;               //Return 1 on succes
    }
    return -1;
}

/**
 * This function checks if a given directory stored in "dirname" exists within the parent_dir. If it does
 * not exist then tries to create it. If it is not able to create it then show erro
 */
int checkDirectory(char* parent_dir, const char* dirname) {
    char* dirpath = concat(parent_dir, dirname);
    int ret_value = 0;
    errno = 0;

    DIR* dir = opendir(dirpath);        //Open the directory
    if (ENOENT == errno) {              //If directory does not exits
        LOG("%s directory does not exist. ", dirpath);
        errno = 0;
        if (mkdir(dirpath, 0777) == -1) {//Try to create it, if it failed, then show error
            fprintf (stderr, "\nUnable to create directory %s. Error Details: %s", dirpath, strerror(errno));
            free(dirpath);
            return 0;
            exit(1);
        }
        else {                            //Directory created successfully and check if it can be opened
            dir = opendir(dirpath);
            LOG("%s directory created successfully", dirpath);
        }
    }

    if(dir) {                           //Check if directory is opened, set return value to 1 which indicates success
        ret_value = 1;
        closedir(dir);                  //Close the directory
    }
    else {                              //Directory failed to opened show error
        fprintf (stderr, "\nError occurred while reading directory %s. Error Details: %s", dirpath, strerror(errno));  //Strerror shows the error message for given errno
        exit(1);
    }

    free(dirpath);
    return ret_value;
}

/**
 * This function splits the filename into tokens with '-' as delimiter. It stores the tokens
 * into args. It expects maximum of total tokens. If there are more than total tokens it returns -1
 * which signify error. Otherwise it modifies the total variable to denote the total number of tokens
 */
int tokenizeFilename(char* filename, int* total, char* args[]) {
    char* token;
    int i = 0;
    token = strtok(filename, "-");

    while (token != NULL) { //While there are more tokens
        if (i >= *total) {  //If we exceed the expected number of tokens break
            break;
        }
        args[i++] = token; //Copy the token to args array
        token = strtok(NULL, "-"); //Generate token for next iteration, NULL indicates that we are using string from previous iteration to split
    }

    /*
     * If we didn't exceed the expected number of tokens, modify the total variable and return success
     */
    if (token == NULL) {
        *total = i;
        return 1;
    }

    return -1;
}