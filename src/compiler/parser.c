//
// Created by lockna on 11/28/19.
//

#include <hawk/parser.h>
#include <hawk/lexer.h>
#include <hawk/token.h>


struct Ha_Token getNextToken(T_List list) {

    static int indexOfToken = 0;
    int counter = 0;

    T_Node* current = list.head;

    while (counter < indexOfToken && current != NULL) {
        current = current->next;
        counter += 1;
    }
    if (current != NULL) {
        indexOfToken += 1;
        return current->value;
    }

}


