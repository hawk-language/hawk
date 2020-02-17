//
// Created by lockna on 12/11/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <hawk/t_list.h>

// Constructor like function for creating a new Token List

struct token_list *new_Token_List()
{
        struct token_list *new = malloc(sizeof(struct token_list));
        new->head = NULL;
        new->tail = NULL;
        return new;
}

// Function for appending a new item to the Token List

void t_append(struct token_list *list, struct Token token)
{
        if (list->head == NULL) {

                list->head = malloc(sizeof(struct token_node));
                list->tail = list->head;
                list->head->previous = NULL;
                list->tail->next = NULL;

                list->head->value.tk = token.tk;
                list->head->value.value = token.value;

                //list->head->value.linenumber = token.linenumber;
                //list->head->value.error = token.error;
                //list->length = 1;

        } else {

                struct token_node *new = malloc(sizeof(struct token_node));
                new->value.tk = token.tk;
                new->value.value = token.value;



                //new->value.linenumber = token.linenumber;
                //new->value.error = token.error;
                list->tail->next = new;
                new->previous = list->tail;
                list->tail = new;
                new->next = NULL;
                //list->length += 1;

        }
}

void t_printList(struct token_list *list)
{

        struct token_node *node = list->head;

        while (node != NULL) {

                char *s = c_ListToString(node->value.value);
                printf("%s", s);
                printf(" : %d\n", node->value.tk);
                node = node->next;

        }
}