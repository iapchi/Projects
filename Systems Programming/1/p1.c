#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "conversion.h"

/**
 * Function to check whether system is big endian or little endian. It can have effect on
 * the order in which the multibyte input is read from the files.
 * Program was written on a different system
 */
int is_big_endian(void)
{
    union {
        uint32_t i;
        char c[4];
    } e = { 0x01000000 };

    return e.c[0];
}

/**
 * Function to swap two values when their poointers are given
 */
int swap(unsigned char* a, unsigned char* b) {
    unsigned char c = *a;
    *a = *b;
    *b = c;
}
/**
 * Main function
 */
int main (int argc, char *argv[]) {

	//Print error if no of input arguments is not 3 or 4
	if(argc != 3 && argc != 4){
		printf("Invalid command. Usage: %s <flag> <inputfile> <outputfile>\n", argv[0]);
		return 0;
	}
	//Print error if there is 3 arguments but wrong flag
	if(argc == 3 && strcmp(argv[1],"-s") != 0){
		printf("Invalid command. Detecting three arguments. Usage allowed: %s '-s' <inputfile>\n", argv[0]);
		return 0;
	}
	//Print error if there is 4 arguments but wrong flag
	if(argc == 4 && strcmp(argv[1],"-b") != 0 && strcmp(argv[1],"-t") != 0){
		printf("Invalid command. Detecting four arguments. Usage allowed: %s '-b' | '-t' <inputfile>\n", argv[0]);
		return 0;
	}
	//Print error if flags are incorrect
	if(strcmp(argv[1],"-s") != 0 && strcmp(argv[1],"-b") != 0 && strcmp(argv[1],"-t") != 0){
		printf("Invalid command. Usage: %s '-s' | '-b' | '-t' <inputfile> <outputfile> \n", argv[0]);
		return 0;
	}
	//-t flag for converting text file to binary file
	if(strcmp(argv[1],"-s") != 0 && strcmp(argv[1],"-b") != 0 && strcmp(argv[1],"-t") == 0) {
		int tek = textToBinaryFile(argv[2], argv[3]);
		if (tek == -1) {
			exit(-1);
		}
	}
	//-b flag for binary file to text file
	else if(strcmp(argv[1],"-s") != 0 && strcmp(argv[1],"-b") == 0 && strcmp(argv[1],"-t") != 0) {
		int tek = binaryToTextFile(argv[2], argv[3]);
		if (tek == -1) {
			exit(-1);
		}
    }
	//-s flag for processing binary file and produce output to stdout
	if(strcmp(argv[1],"-s") == 0 && strcmp(argv[1],"-b") != 0 && strcmp(argv[1],"-t") != 0){
		int tek = printStats(argv[2]);
		if (tek == -1) {
			exit(-1);
		}
	}
	return 0;
}