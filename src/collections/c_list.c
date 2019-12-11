//
// Created by lockna on 12/11/19.
//

#include <stdlib.h>
#include <stdio.h>
#include "c_list.h"

List* new_List() {

    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;

}

void append(List* list, char ch) {

    if (list->head == NULL) {

        list->head = malloc(sizeof(Node));
        list->tail = list->head;
        list->head->previous = NULL;
        list->tail->next = NULL;
        list->head->value = ch;
        list->length = 1;

    } else {

        Node* new = malloc(sizeof(Node));
        new->value = ch;
        list->tail->next = new;
        new->previous = list->tail;
        list->tail = new;
        list->length += 1;
    }
}

void printList(List* list) {

    Node* current = list->head;

    if (current == NULL) {
        fprintf(stderr, "NullPointerException (list.c printList)");
    } else {

        while (current != NULL) {
            printf("%c", current->value);
            current = current->next;
        }

    }
}