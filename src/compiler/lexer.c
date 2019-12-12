
#include <stdlib.h>
#include "lexer.h"
#include "../collections/c_list.h"
#include "../collections/t_list.h"
#include "token.h"


Lexer new_Lexer(char* file) {
    Lexer lexer;
    lexer.file = file;
    lexer.clist = malloc(sizeof(struct c_list));
    lexer.tlist = malloc(sizeof(struct t_list));
    lexer.lex = lexing;
    lexer.eval_List = evaluate_List;
    lexer.lexer_inputFile = lexer_fileInput;
    return lexer;
}


int lexing(struct Ha_Lexer* lexer) {
    lexer_fileInput(lexer);
    lexer->tlist = lexer->eval_List(lexer->clist);
    return 1;
}

int lexer_fileInput(struct Ha_Lexer* lexer) {

    char c;
    FILE *fp = fopen(lexer->file, "r");

    if (fp == NULL) {
        fprintf(stderr, "No file given");
        exit(-1);
    }

    while ((c = fgetc(fp)) != EOF) {
        append(lexer->clist, c);
    }
    return 1;

}

T_List* evaluate_List(struct c_list* list) {



}

enum Ha_Tokens isIdentifier(char *value) {

    // Hier wird ueberprueft ob der Identifier als Variablenname gueltig ist
    return IDENTIFIER;

}






