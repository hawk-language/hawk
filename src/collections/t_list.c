//
// Created by lockna on 12/11/19.
//

#include <stdlib.h>
#include "t_list.h"

// Constructor like function for creating a new Token List

struct t_list* new_Token_List() {

    T_List* new = malloc(sizeof(T_List));
    new->head = NULL;
    new->tail = NULL;

}

// Function for appending a new item to the Token List

struct t_list* _t_append(T_List* list, struct Ha_Token token) {

    if (list->head == NULL) {

        list->head = malloc(sizeof(T_Node));
        list->tail = list->head;
        list->head->previous = NULL;
        list->tail->next = NULL;

        list->head->value.tk = token.tk;
        list->head->value.value = token.value;
        list->head->value.linenumber = token.linenumber;
        list->head->value.error = token.error;

        list->length = 1;

    } else {

        T_Node* new = malloc(sizeof(T_Node));

        new->value.tk = token.tk;
        new->value.value = token.value;
        new->value.linenumber = token.linenumber;
        new->value.error = token.error;

        list->tail->next = new;
        new->previous = list->tail;
        list->tail = new;
        list->length += 1;
    }

}