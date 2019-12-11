//
// Created by lockna on 11/28/19.
//
#include <stdio.h>
#include <string.h>
#include "../collections/c_list.h"
#include "token.h"

#ifndef HAWK_LEXER_H
#define HAWK_LEXER_H

typedef struct Ha_Lexer {
    char *file;
    // Tokenliste
} Lexer;

Lexer initialize_lex(char* file);
int lex(struct Ha_Lexer* lexer, List* list);

#endif //HAWK_LEXER_H
