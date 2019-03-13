    /**
      *Jacky Li

      */
#include "archive.h"

//Archive creation
void archive(char** filenames, int numFiles, char* archivename) {
    //TODO: Handle case where archive already exists

    int i;
    FILE *archive = fopen (archivename, "wb");

    if (archive == NULL) {
        printf ("Error creating archive %s.", archivename);
    }
    else {

        LOG("\nStoring number of files: %d", numFiles);

        //Write number of files
        fwriteInt (&numFiles, sizeof (numFiles), 1, archive);

        for (i = 0; i < numFiles; ++i) {
            LOG ("\n\nStoring file %d: %s", i, filenames[i]);
            store(archive, filenames[i]);
        }
        fclose(archive);
    }
}
//Archive extraction
void unarchive(char* archivefile) {
    int i, numFiles;
    FILE *archive = fopen (archivefile, "rb");

    if (archive == NULL) {
        printf ("Error opening archive %s for reading.", archivefile);
    }
    else {
        //Read number of files
        freadInt(&numFiles, sizeof (numFiles), 1, archive);
        LOG("\nReading number of files: %d", numFiles);

        for (i = 0; i < numFiles; ++i) {
            LOG ("\n\nRetrieving file: %d", i + 1);
            retrieve(archive);
        }
        fclose(archive);
    }
}


//HELPER FUNCTIONS
/**
 * Function to store the file with name filename in the archive openend in handle ar
 * Returns 0 on success and non-negative on failure
 */
int store(FILE* archive, char* filename) {
    char len = strlen(filename), ch;
    int ret = 0;
    int size, i;
    FILE* file;

    LOG ("\n\tWriting length of filename %d", len);
    LOG ("\n\tWriting filename %s", filename);

    fwrite(&len, sizeof(len), 1, archive);
    fwrite(filename, (int)len + 1, 1, archive);

    file = fopen (filename, "rb");
    if (file == NULL) {
        printf ("\n\tUnable to open file %s for reading.", filename);
        ret = 1;
    } else {
        size = external_file_size(file);
        LOG ("\n\tWriting size of file: %d", size);
        fwriteInt(&size, sizeof(size), 1, archive);

        LOG ("\n\tWriting file to archive");
        for (i = 0; i < size; ++i) {
            fread(&ch, sizeof(ch), 1, file);
            fwrite(&ch, sizeof(ch), 1, archive);
        }

        fclose(file);
    }

    return ret;
}

/**
 * Function to retrieve the file with name filename in the archive openend in handle ar
 * Returns 0 on success and non-negative on failure
 */
int retrieve(FILE* archive) {
    int ret = 0, i;
    char ch;
    int file_size;
    char* filename = read_file_info(archive, &file_size);
    LOG ("\n\tRead file name: %s and file size %d.\n\tReading file.", filename, file_size);

    FILE *file = fopen (filename, "wb");
    if (file == NULL) {
        printf ("\nError creating file %s", filename);
        ret = 1;
    } else {
        for (i = 0; i < file_size; ++i) {
            fread(&ch, sizeof(ch), 1, archive);
            fwrite(&ch, sizeof(ch), 1, file);
        }
        LOG("\nExtracted file successfully.");
    }

    free(filename);
    fclose(file);
    return ret;
}