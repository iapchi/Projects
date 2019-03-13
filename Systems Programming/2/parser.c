    /**
      *Jacky Li

      */
#include "def.h"
#include "parser.h"
#include "archive.h"
#include "list.h"

//function prototypes for main
void parser_a(int argc, char** argv) {
    archive(argv + 3, argc - 3, argv[2]);
}

void parser_u(int argc, char** argv) {
    unarchive(argv[2]);
}

void parser_l(int argc, char** argv) {
    list_details(argv[2]);
}

void parser_v(int argc, char** argv) {
    verify(argv + 3, argc - 3, argv[2]);
}
