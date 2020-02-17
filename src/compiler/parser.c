//
// Created by lockna on 11/28/19.
//

#include <hawk/parser.h>
#include <hawk/lexer.h>
#include <hawk/token.h>


struct Token getNextToken(struct token_list list)
{

        static int indexOfToken = 0;
        int counter = 0;

        struct token_node *current = list.head;

        while (counter < indexOfToken && current != NULL) {
                current = current->next;
                counter += 1;
        }
        if (current != NULL) {
                indexOfToken += 1;
                return current->value;
        }

}


