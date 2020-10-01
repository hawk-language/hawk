//
// Created by lockna on 11/28/19.
//
#include <stdio.h>
#include <string.h>
#include <hawk/token_list.h>
#include <hawk/token.h>

#ifndef HAWK_LEXER_H
#define HAWK_LEXER_H

// The Lexer struct which contains the character list, the file, the token
// list and the function pointers

struct Lexer {

    char *path;
    char *buffer;
    struct token_list *t_list;

};

struct Lexer new_Lexer(char *file);
int lexing(struct Lexer *lexer);

#endif //HAWK_LEXER_H
