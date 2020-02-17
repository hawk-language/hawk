//
// Created by lockna on 11/28/19.
//
#include <stdio.h>
#include <string.h>
#include <hawk/c_list.h>
#include <hawk/t_list.h>
#include <hawk/token.h>

#ifndef HAWK_LEXER_H
#define HAWK_LEXER_H

// The Lexer struct which contains the character list, the file, the token list and the function pointers

struct Lexer {

        char *file;
        struct char_list *c_list;
        struct token_list *t_list;

};

struct Lexer new_Lexer(char *file);
static int lexer_fileInput(struct Lexer *lexer);
int lexing(struct Lexer *lexer);
static int evaluate_List(struct Lexer *lexer);
static int isSeperator(char value);
static int isSingleToken(char value);
static enum Ha_Tokens getTokenFromValue(char *value);
static int isKeyword(char *value, int *token);
static int isNumber(const char *value);

#endif //HAWK_LEXER_H
