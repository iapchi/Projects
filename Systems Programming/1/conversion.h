#ifndef __CONVERSION_H__
#define __CONVERSION_H__
/**
 * Function protoypes
 */
int is_big_endian(void);
int textToBinaryFile(char* inputFile, char* outputFile);
int binaryToTextFile(char* inputFile, char* outputFile);
int printStats(char* inputFile);
int swap(unsigned char* a, unsigned char* b);

#endif