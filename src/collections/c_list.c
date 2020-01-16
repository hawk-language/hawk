//
// Created by lockna on 12/11/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <hawk/c_list.h>

// A constructor like function for initializing a character list
List*
new_List() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->append = _list_append;
    list->printList = _c_printList;
    list->clearList = _c_clearList;
    list->toString = _c_ListToString;
    return list;
}

// Adds a further char to the character list
void
_list_append(List* list, char ch) {

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

// Prints the whole list to the console (only for debugging purposes)
void
_c_printList(List* list) {

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

void
_c_clearList(List* list) {

    Node* tail = list->tail;

    while (tail->previous != NULL) {

        tail->next = NULL;
        tail->value = 0;
        tail = tail->previous;

    }
    tail->value = 0;
    list->length = 0;

}

// function written by an user of morpheus tutorials
char*
_c_ListToString(List* list) {
    Node* head = list->head;
    char *string = malloc(sizeof(char) * (list->length + 1));
    int i = 0;

    while (head) {
        string[i++] = head->value;
        head = head->next;
    }
    string[i] = '\0';
    return string;
}

int
isEmpty(List* list) {
    int isEmpty = 0;
    if (list->head == NULL && list->tail == NULL) {
        isEmpty = 1;
    }
    return isEmpty;
}