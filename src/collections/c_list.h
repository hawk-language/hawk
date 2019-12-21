//
// Created by lockna on 12/11/19.
//

#ifndef HAWK_C_LIST_H
#define HAWK_C_LIST_H

// The single Node of the character list

typedef struct c_Node {

    char value;
    struct c_Node* next;
    struct c_Node* previous;

} Node;

// The actual List, which contains the head, tail, length and the function pointers

typedef struct c_list {

    int length;
    struct c_Node* head;
    struct c_Node* tail;
    void (*append) (struct c_list* list, char ch);
    void (*printList) (struct c_list* list);
    void (*clearList) (struct c_list* list);
    const char* (*toString) (struct c_list* list);

} List;

// Function Prototypes

List* new_List();
void _list_append(List* list, char ch);
void _c_printList(List* list);
void _c_clearList(List* list);
char* _c_ListToString(List* list);

#endif //HAWK_C_LIST_H
