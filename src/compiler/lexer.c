
#include <stdlib.h>
#include "lexer.h"
#include "../collections/c_list.h"
#include "../collections/t_list.h"
#include "token.h"

// Functions for generating a new lexer

Lexer new_Lexer(char* file) {
    Lexer lexer;
    lexer.file = file;
    lexer.clist = malloc(sizeof(struct c_list));
    lexer.clist->append = _list_append;
    lexer.clist->printList = _c_printList;

    lexer.tlist = malloc(sizeof(struct t_list));
    lexer.tlist->t_append = _t_append;

    lexer.lex = _lexing;
    lexer.eval_List = _evaluate_List;
    lexer.lexer_inputFile = _lexer_fileInput;
    return lexer;
}

// The main function of the lexer, which calls other functions

int _lexing(struct Ha_Lexer* lexer) {
    lexer->lexer_inputFile(lexer);
    lexer->eval_List(lexer);
    return 1;
}

// Function for saving the file, given as input, to the lexers file member, as character list

int _lexer_fileInput(struct Ha_Lexer* lexer) {

    char c;
    FILE *fp = fopen(lexer->file, "r");

    if (fp == NULL) {
        fprintf(stderr, "No file given");
        exit(-1);
    }

    while ((c = fgetc(fp)) != EOF) {
        lexer->clist->append(lexer->clist, c);
    }
    return 1;

}

// Function that evaluates the list from the lexer and saves the tokens to the token list from the lexer

int _evaluate_List(struct Ha_Lexer* lexer) {

    Node* list = lexer->clist->head;

    while (list->next != NULL) {



    }

}

int isSeperator(char seperator) {

    if (seperator == '(' || seperator == ')' || seperator == '[' || seperator == ']' || seperator == '{' || seperator == '}' || )

}






