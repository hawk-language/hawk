//
// Created by lockna on 11/28/19.
//
#include "compiler/lexer.h"
#include "collections/c_list.h"

int main(int argc, char *argv[]) {

    Lexer lexer = new_Lexer("../test.hk");
    lexer.lex(&lexer);



}
