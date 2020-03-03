//
// Created by lockna on 12/11/19.
//
#include <hawk/token.h>

#ifndef HAWK_T_LIST_H
#define HAWK_T_LIST_H

// Node of the token list

struct token_node {

    // enum Ha_Token
    struct Token token;

    struct token_node *next;
    struct token_node *previous;

};

// Actual token list

struct token_list {

    //int length;
    struct token_node *head;
    struct token_node *tail;

};


void token_append(struct token_list *list, struct Token tok);
struct token_list *new_Token_List();
void token_printList(struct token_list *list);

#endif //HAWK_T_LIST_H
