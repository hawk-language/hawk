//
// Created by lockna on 11/28/19.
//
#include <stdio.h>
#include <string.h>
#ifndef HAWK_LEXER_H
#define HAWK_LEXER_H

enum Ha_Tokens {
    SPACE,
    COMMA,
    DOT,
    COLON,
    SEMICOLON,
    OPEN_PAREN,     // (
    CLOSE_PAREN,    // )
    OPEN_CURL,      // {
    CLOSE_CURL,     // }
    OPEN_BRACK,     // [
    CLOSE_BRACK,    // ]
    IDENTIFIER,
    NONE,

    M_PLUS,           // +
    M_MINUS,          // -
    M_MULTI,          // *
    M_DIV,            // /
    M_CIRC,            // ^

    KW_FUNC,
    KW_INT,
    KW_STR,
    KW_DOUBLE,
    KW_CHAR,
    KW_FOR,
    KW_WHILE,
    KW_DO,
    KW_IF,
    KW_ELSE
};

struct Ha_Token {
    enum Ha_Tokens tk;
    char *value;

    // For error handling
    int linenumber;
    char* error;
};

typedef struct Ha_Lexer {
    char *file;
    // Tokenliste
} Lexer;

Lexer initialize_lex(char* file);
int lex(struct Ha_Lexer* lexer);

#endif //HAWK_LEXER_H
