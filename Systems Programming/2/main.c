    /**
      *Jacky Li

      */
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "utility.h"

    /**
      *Jacky Li

      */
//main function handling the initial input and their corresponding flag values and arguments
int main(int argc, char** argv) {

    if (argc < 3) {
        printf ("\nUsage: archiver [-a archive_name files] [-l archive_name] [-u archive_name] [-v archive_name file_names]\n");
        return 0;
    }

    if (strcmp(argv[1], "-a") == 0 && argc >= 4 ) {
        parser_a(argc, argv);
    }
    else if (strcmp(argv[1], "-u") == 0 && argc == 3) {
        parser_u(argc, argv);
    }
    else if (strcmp(argv[1], "-l") == 0 && argc == 3) {
        parser_l(argc, argv);
    }
    else if (strcmp(argv[1], "-v") == 0 && argc >= 4) {
        parser_v(argc, argv);
    }
    else {
        printf ("\nInvalid Use");
        printf ("\nUsage: archiver [-a archive_name files] [-l archive_name] [-u archive_name] [-v archive_name file_names]\n");
    }
    return 0;
}