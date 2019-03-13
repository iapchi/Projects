#include "filetype.h"
#include "def.h"

/*Private methods local to this file*/
int isAudioFile(char* ext);
int isVideoFile(char* ext);
int isWordFile(char* ext);
int isTextFile(char* ext);
int isImageFile(char* ext);

/**
 * This function returns the file type for a given filename
 */
int getfiletype(char* filename) {
    //Get the extension from the filename
    char* ext = getExtension(filename);
    int filetype;

    LOG("Filename: %s, Extension: %s", filename, ext);

    //Check the filenames and return corresponding macro constant
    if (isAudioFile(ext)) {
        filetype = AUDIO;
    }
    else if (isVideoFile(ext)) {
        filetype = VIDEO;
    }
    else if (isWordFile(ext)) {
        filetype = WORD;
    }
    else if (isTextFile(ext)) {
        filetype = TEXT;
    }
    else if (isImageFile(ext)) {
        filetype = IMAGE;
    }
    else {
        filetype = OTHER;
    }
    return filetype;
}

/*
 * Function to check if given file is audio file
 */
int isAudioFile(char* ext) {
    return strcmp(ext, "mp3") == 0;
}


/*
 * Function to check if given file is video file
 */
int isVideoFile(char* ext) {
    return strcmp(ext, "mkv") == 0;
}


/*
 * Function to check if given file is word file
 */
int isWordFile(char* ext) {
    return strcmp(ext, "docx") == 0;
}


/*
 * Function to check if given file is text file
 */
int isTextFile(char* ext) {
    return strcmp(ext, "txt") == 0;
}


/*
 * Function to check if given file is image file
 */
int isImageFile(char* ext) {
    return strcmp(ext, "jpg") == 0 || strcmp(ext, "png") == 0;
}

/**
 * This method returns the extension part of the filename
 */
char* getExtension(char* filename) {
    int len = strlen(filename); //Get the length of string
    int j = 0;                  //Get the position where '.' is present from the end
    int i;
    for (i = len - 1; i >= 0 && filename[i] != '.'; --i) {
        j++;
    }
    return filename + len - j;  //Return the pointer to characer after last '.'
}