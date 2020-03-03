//
// Created by lockna on 12/11/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <hawk/token_list.h>

// Constructor like function for creating a new Token List

struct token_list *new_Token_List()
{
        struct token_list *new = malloc(sizeof(struct token_list));
        new->head = NULL;
        new->tail = NULL;
        return new;
}

// Function for appending a new item to the Token List

void token_append(struct token_list *list, struct Token tok)
{

        if (list->head == NULL) {

                list->head = malloc(sizeof(struct token_node));
                list->head->token.linenumber = tok.linenumber;
                list->head->token.value = tok.value;
                list->head->token.TokenType = tok.TokenType;
                list->head->next = NULL;
                list->head->previous = NULL;
                list->tail = list->head;

        } else {

                list->tail->next = malloc(sizeof(struct token_node));
                list->tail->next->previous = list->tail;
                list->tail = list->tail->next;
                list->tail->next = NULL;

                list->tail->token.linenumber = tok.linenumber;
                list->tail->token = tok;
                list->tail->token.value = tok.value;

        }

}

void token_printList(struct token_list *list)
{

        struct token_node *node = list->head;

        while (node != NULL) {

                printf("%s", node->token.value);
                printf(" : %d : %d\n", node->token.TokenType, node->token.linenumber);
                node = node->next;
                fflush(stdout);

        }
}

