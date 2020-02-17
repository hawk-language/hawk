//
// Created by lockna on 11/28/19.
//

#ifndef HAWK_PARSER_H
#define HAWK_PARSER_H

#include <hawk/lexer.h>

struct ExprAST {
        int i;
};

struct NumberExprAST {
        struct ExprAST;
};

struct VariableExprAST {
        struct ExprAST;
};

struct CallExprAST {
        struct ExprAST;
};

struct PrototypeAST {
        struct ExprAST;
};

struct FunctionAST {
        struct ExprAST;
};


struct Token getNextToken(struct token_list list);

#endif //HAWK_PARSER_H
