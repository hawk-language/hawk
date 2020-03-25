//
// Created by lockna on 11/28/19.
//
#include <hawk/lexer.h>
#include <hawk/parser.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

        struct Lexer lexer = new_Lexer(argv[1]);

        if (argc == 1) {
                printf("Welcome to the Hawk Programming Language!\n");
                printf("Check it out on Github: https://github.com/hawk-language"
                       "/hawk\n");
                exit(0);
        }

        lexing(&lexer);


        return 0;
}
