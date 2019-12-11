//
// Created by lockna on 12/11/19.
//

#ifndef HAWK_C_LIST_H
#define HAWK_C_LIST_H

typedef struct c_Node {

    char value;
    struct c_Node* next;
    struct c_Node* previous;

} Node;

typedef struct c_list {

    int length;
    struct c_Node* head;
    struct c_Node* tail;

} List;

List* new_List();
void append(List* list, char ch);
void printList(List* list);

#endif //HAWK_C_LIST_H
