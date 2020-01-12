//
// Created by lockna on 11/28/19.
//

#ifndef HAWK_TOKEN_H
#define HAWK_TOKEN_H

#include <hawk/c_list.h>
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
    NUMBER,

    M_PLUS,           // +
    M_MINUS,          // -
    M_MULTI,          // *
    M_DIV,            // /
    M_CIRC,            // ^
    M_MOD,             // %

    OP_EQUAL,
    OP_NOTEQ,
    OP_ISEQ,

    BIN_OR,
    BIN_AND,

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
    enum Ha_Tokens tk;
    List* value;

    // For error handling
    // int linenumber;
    // char* error;
};

typedef struct Ha_Token Token;

#endif //HAWK_TOKEN_H
