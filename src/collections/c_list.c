//
// Created by lockna on 12/11/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <hawk/c_list.h>

// A constructor like function for initializing a character list
struct char_list *new_List()
{
        struct char_list *list = malloc(sizeof(struct char_list));
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;

        return list;
}

// Adds a further char to the character list
void list_append(struct char_list *list, char ch)
{

        if (list->head == NULL) {

                list->head = malloc(sizeof(struct char_node));
                list->tail = list->head;
                list->head->previous = NULL;
                list->tail->next = NULL;
                list->head->value = ch;
                list->length = 1;

        } else {

                struct char_node *new = malloc(sizeof(struct char_node));
                new->value = ch;
                list->tail->next = new;
                new->previous = list->tail;
                list->tail = new;
                list->length += 1;
        }
}

// Prints the whole list to the console (only for debugging purposes)
void char_printList(struct char_list *list)
{

        struct char_node *current = list->head;

        if (current == NULL) {
                fprintf(stderr, "NullPointerException (list.c printList)");
        } else {
                while (current != NULL) {
                        printf("%c", current->value);
                        current = current->next;
                }
        }
}

void c_clearList(struct char_list *list)
{

        struct char_node *tail = list->tail;

        while (tail->previous != NULL) {

                tail->next = NULL;
                tail->value = 0;
                tail = tail->previous;

        }
        tail->value = 0;
        list->length = 0;

}

// function written by an user of morpheus tutorials
char *c_ListToString(struct char_list *list)
{
        struct char_node *head = list->head;
        char *string = malloc(sizeof(char) * (list->length + 1));
        int i = 0;

        while (head) {
                string[i++] = head->value;
                head = head->next;
        }
        string[i] = '\0';
        return string;
}

int isEmpty(struct char_list *list)
{
        int isEmpty = 0;
        if (list->head == NULL && list->tail == NULL) {
                isEmpty = 1;
        }
        return isEmpty;
}