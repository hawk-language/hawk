//
// Created by lockna on 11/28/19.
//
#include "compiler/lexer.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    setbuf(stdout, NULL);
    Lexer lexer = new_Lexer(argv[1]);
    lexer.lex(&lexer);

    return 0;
}
