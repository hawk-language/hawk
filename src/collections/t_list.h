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

    //int length;
    struct t_Node* head;
    struct t_Node* tail;
    void (*t_append)(struct t_list* list, struct Ha_Token token);
    void (*t_printList)(struct t_list* list);

} T_List;


void _t_append(T_List* list, struct Ha_Token token);
struct t_list* new_Token_List();
void _t_printList(T_List* list);

#endif //HAWK_T_LIST_H
