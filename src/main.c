//
// Created by lockna on 11/28/19.
//
#include "compiler/lexer.h"

int main(int argc, char *argv[]) {
    printf("hello");
    Lexer le = initialize_lex("../test.hk");
    lex(&le);
}
