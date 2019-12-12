//
// Created by lockna on 11/28/19.
//
#include <stdio.h>
#include <string.h>
#include "../collections/c_list.h"
#include "../collections/t_list.h"
#include "token.h"

#ifndef HAWK_LEXER_H
#define HAWK_LEXER_H


typedef struct Ha_Lexer {
    char *file;
    struct c_list *clist;
    struct t_list *tlist;
    int (*lex)(struct Ha_Lexer* lexer);
    int (*lexer_inputFile)(struct Ha_Lexer* lexer);
    T_List* (*eval_List) (struct c_list* list);
} Lexer;




Lexer new_Lexer(char* file);
int lexer_fileInput(struct Ha_Lexer* lexer);
int lexing(struct Ha_Lexer* lexer);
T_List* evaluate_List(struct c_list* list);

#endif //HAWK_LEXER_H
