    /**
      *Jacky Li

      */
#include "list.h"

    /**
      * List the total bytes within the file's and their parent archive name along with the size and quanitity of files
      */
void list_details(char* archivename) {
    FILE* archive = fopen(archivename, "rb");
    if (archive == NULL) {
        printf ("\nUnable to open archive: %s", archivename);
        return;
    } else {
        unsigned int archive_size = external_file_size(archive);
        int numFiles = 0, i;

        freadInt (&numFiles, sizeof (numFiles), 1, archive);
        LOG("\nReading number of files: %d", numFiles);

        printf ("%s: Total size: %u bytes containing %d files.", archivename, archive_size, numFiles);
        LOG ("\n\nRetrieving files.");
        for (i = 0; i < numFiles; ++i) {
            display_file_info(archive);
        }
    }
}
    /**
      * Display file size in bytes
      */
void display_file_info(FILE* archive) {
    unsigned int file_size;
    char* filename = read_file_info(archive, &file_size);
    printf ("\n%s \t\t %u bytes", filename, file_size);
    fseek(archive, file_size, SEEK_CUR);
    free(filename);
}
    /**
      * Vertify function, reads the archieve
      */
int verify(char** filenames, int numFilesOrig, char* archivename) {
    FILE *archive = fopen (archivename, "rb");
    if (archive == NULL) {
        printf ("Error opening archive.");
        return -2;
    }

    /**
     * Check if expected archive size is same as actual archive size
     */
    unsigned int expected_archive_size = 4;
    int i = 0;
    for (i = 0; i < numFilesOrig; ++i) {
        expected_archive_size += 1 + strlen(filenames[i]) + 1;
        FILE* file = fopen(filenames[i], "rb");
        expected_archive_size += 4 + external_file_size(file);
        fclose(file);
    }
    LOG("Expected archive size: %u", expected_archive_size);
    int diff_bytes = expected_archive_size - external_file_size(archive);
    if (diff_bytes > 0) { /* Expected archive size is more */
        printf ("Archive Missing %d bytes.", diff_bytes);
    }
    else if (diff_bytes == 0) { /* Expected archive size equals actual archive size, so check individual files for errors */
        int numFiles = 0, i, ret = 0;
        freadInt (&numFiles, sizeof (numFiles), 1, archive);
        LOG("\nReading number of files: %d", numFiles);

        for (i = 0; i < numFiles && !ret; ++i) {
            LOG("Checking file: %s", filenames[i]);
            ret = checkFile(archive, filenames[i]);
        }
        if (ret == 0) {
            printf ("Archive verified.");
        }
    }
    else { /* Expected archive has smaller size than actual archive */
        printf ("Has extra %d bytes", -diff_bytes);
    }

    fclose(archive);
}

/**
 * It is assumed user specifies files that are supposed to be in archive and in correct order
 * It checks whether archive has that filename, and whether data is valid or not
 */
int checkFile(FILE* archive, char* filename) {
    unsigned int a_file_size, diff_bytes = 0, j, index;
    char* a_filename = read_file_info(archive, &a_file_size);
    int ret = 0;
    if (strcmp(a_filename, filename) == 0) { /* If filenames are same, then check for data */
        FILE* file = fopen(filename, "rb");
        if (file == NULL) { /* If file could not be opened */
            printf ("Could not open input file %s fore reading.", filename);
            ret = 1;
        }
        else {
            unsigned int file_size = external_file_size(file); /* If file size differs then show message */
            if (file_size > a_file_size) {
                printf ("Archive Missing %d bytes", file_size - a_file_size);
                ret = a_file_size - file_size;
            }
            else { /* Check byte by byte data for errors */
                char ch1, ch2;
                unsigned int j = 0;
                while (j < file_size && ret == 0) {
                    fread(&ch1, sizeof(ch1), 1, archive);
                    fread(&ch2, sizeof(ch2), 1, file);
                    if (ch1 != ch2) { /* If any byte differs then archive is corrupted */
                        printf ("Archive is Corrupted");
                        ret = 1;
                    }
                    ++j;
                }
            }
        }
        fclose(file);
    } else {
        LOG("Filename does not match with filename in archive");
        printf ("Archive is Corrupted");
        ret = 1;
    }

    free(a_filename);
    return ret;
}