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
            STRING_LITERAL,

            M_PLUS,           // +
            M_MINUS,          // -
            M_MULTI,          // *
            M_DIV,            // /
            M_CIRC,            // ^
            M_MOD,             // %

            OP_ASSIGN,
            OP_EQUAL,
            OP_NOTEQ,
            OP_ISEQ,
            OP_LT,              // Less than
            OP_GT,              // Greather than

            BIN_OR,
            BIN_AND,
            BIN_XOR,

            KW_FUNC,
            KW_INT,
            KW_STR,
            KW_DOUBLE,
            KW_CHAR,
            KW_FOR,
            KW_WHILE,
            KW_DO,
            KW_IF,
            KW_ELSE,
            KW_STRUCT,
            KW_UNION,
            KW_ENUM,
            KW_CLASS
};

// Struct for a single token

struct Token {
            int tk;
            struct char_list *value;

            // For error handling
            int linenumber;
            char *error;
};

#endif //HAWK_TOKEN_H
