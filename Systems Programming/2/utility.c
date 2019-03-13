    /**
      *Jacky Li

      */
#include "utility.h"

 /*
  *Function to measure external_file_size
  */
unsigned int external_file_size(FILE* file) {
    unsigned int size;
    if (file == NULL) return 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}


/*int file_exist (char *filename) {
    struct stat   buffer;
    return (stat (filename, &buffer) == 0);
}*/
  /*
   *Reads the file's name
   */
char* read_file_info(FILE* archive, unsigned int* sz) {
    char ch, *filename;
    unsigned int filename_size;
    int file_size;
    int ret = 0;

    fread(&ch, sizeof(ch), 1, archive);
    filename_size = ch;
    filename_size++;

    filename = malloc(sizeof(char) * filename_size);
    fread(filename, filename_size, 1, archive);
    fread(&file_size, sizeof(file_size), 1, archive);
    if (is_little_endian() == 1) {
        get_big_endian(&file_size);
    }
    *sz = file_size;
    return filename;
}
 /*
  *Internal reading of the file
  */
int contains(char** strings, int len, char* target) {
    int i;
    for (i = 0; i < len; ++i) {
        if (strcmp(strings[i], target) == 0) {
            return i;
        }
    }
    return -1;
}


int is_little_endian() {
    int n = 1;
    // little endian if true
    return (*(char *)&n == 1);
}

void get_big_endian(void* x) {
    char* c = (char*)x;
    swap(c, c + 3);
    swap(c + 1, c + 2);
}

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int fwriteInt(int *ptr, size_t sz, int n, FILE* file) {
    if (is_little_endian() == 1) {
        int t = *ptr;
        get_big_endian(&t);
        return fwrite (&t, sz, n, file);
    }
    else {
        return fwrite (ptr, sz, n, file);
    }
}

int freadInt(int *ptr, size_t sz, int n, FILE* file) {
    int ret = fread (ptr, sz, n, file);
    if (is_little_endian() == 1) {
        get_big_endian(ptr);
    }
    return ret;
}