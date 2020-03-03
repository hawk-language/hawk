//
// Created by lockna on 11/28/19.
//
#include <hawk/lexer.h>
#include <hawk/parser.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        // todo: lexer add comment support
        // todo: lexer == is recognized as two seperate =

        if (argc == 1) {
                printf("Welcome to the Hawk Programming Language!\n");
                printf("Check it out on Github: https://github.com/hawk-language"
                       "/hawk\n");
                exit(0);
        }
        struct Lexer lexer = new_Lexer(argv[1]);
        lexing(&lexer);

        return 0;
}
