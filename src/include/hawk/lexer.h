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
static char *lexer_readFile(const char *path);
int lexing(struct Lexer *lexer);
static int evaluate_File(struct Lexer *lexer);
static int isDigit(char value);
static int isAlpha(char c);
static struct Token checkKeyword(char *buffer, int *current);
static char *getNextAlpha(char *buffer, int *current);
static struct Token number(char *buffer, int *current);
static struct Token string(const char *buffer, int *current);
static struct Token makeToken(char *value, int tok);

#endif //HAWK_LEXER_H
