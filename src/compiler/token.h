//
// Created by lockna on 11/28/19.
//

#ifndef HAWK_TOKEN_H
#define HAWK_TOKEN_H

#include "../collections/c_list.h"
// All possible Tokens

enum Ha_Tokens {
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
    M_MOD,             // %

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

// Struct for a single token

struct Ha_Token {
    enum Ha_Tokens tk; // todo: rename
    List* value;

    // For error handling
    // int linenumber;
    // char* error;
};

typedef struct Ha_Token Token;

#endif //HAWK_TOKEN_H
