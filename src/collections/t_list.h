//
// Created by lockna on 12/11/19.
//
#include "../compiler/token.h"
#ifndef HAWK_T_LIST_H
#define HAWK_T_LIST_H

// Node of the token list

typedef struct t_Node {

    struct Ha_Token value;
    struct t_Node* next;
    struct t_Node* previous;

} T_Node;

// Actual token list

typedef struct t_list {

    int length;
    struct t_Node* head;
    struct t_Node* tail;
    struct t_list* (*t_append)(struct t_list* list, struct Ha_Token token);

} T_List;


struct t_list* _t_append(T_List* list, struct Ha_Token token);

#endif //HAWK_T_LIST_H
