//
// Created by lockna on 12/11/19.
//

#ifndef HAWK_C_LIST_H
#define HAWK_C_LIST_H

struct char_node {

        char value;
        struct c_node *next;
        struct c_node *previous;

};

struct char_list {

        int length;
        struct char_node *head;
        struct char_node *tail;


};


struct char_list *new_List();
void list_append(struct char_list *list, char ch);
void c_printList(struct char_list *list);
void c_clearList(struct char_list *list);
char *c_ListToString(struct char_list *list);
int isEmpty(struct char_list *list);

#endif //HAWK_C_LIST_H
