//
// Created by lockna on 11/28/19.
//

#ifndef HAWK_TOKEN_H
#define HAWK_TOKEN_H

// All possible Tokens

enum TokenType {

    // Single-character tokens.
            OPEN_PAREN, CLOSE_PAREN, OPEN_CURL, CLOSE_CURL, OPEN_BRACK, CLOSE_BRACK, COMMA, DOT, MINUS, PLUS, COLON,
    SEMICOLON,
    SLASH,
    STAR,
    CIRC,
    MOD,

    // One or two character tokens
            BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER, GREATER_EQUAL, LESS, LESS_EQUAL, PLUS_PLUS, MINUS_MINUS,

    AND, OR,

    // Literals
            IDENTIFIER, STRING, NUMBER,

    // Keywords

    STRUCT, FUN, IF, ELSE, FOR,
    WHILE,
    DO,
    RETURN,
    IMPORT,
    INT,
    CHAR,
    STR,
    DECIMAL,
    BOOL,
    ERR

};

struct Token {

    int TokenType;
    char *value;

    int linenumber;

};


#endif //HAWK_TOKEN_H
