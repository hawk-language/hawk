//
// Created by lockna on 11/28/19.
//
#include <hawk/lexer.h>
#include <hawk/parser.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    //setbuf(stdout, NULL);
    if(argc == 1){
        printf("Welcome to the Hawk Programming Language!\n");
        printf("Check it out on Github: https://github.com/hawk-language/hawk\n");
        exit(0);
    }
    Lexer lexer = new_Lexer(argv[1]);
    lexer.lex(&lexer);

    return 0;
}
