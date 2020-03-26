//
// Created by lockna on 11/28/19.
//

#ifndef HAWK_PARSER_H
#define HAWK_PARSER_H

#include <hawk/lexer.h>

struct Parser {

    struct token_list *TokenList;
    struct AST *ast;
    struct token_node *currentToken;

};

#endif //HAWK_PARSER_H
