
#include <stdlib.h>
#include "lexer.h"

enum Ha_Tokens getEnum(char *value) {
}

Lexer initialize_lex(char* file) {

    Lexer lexer;
    lexer.file = file;
    return lexer;
}


enum Ha_Tokens isIdentifier(char *value) {

    // Hier wird ueberprueft ob der Identifier als Variablenname gueltig ist
    return IDENTIFIER;

}

int lex(struct Ha_Lexer* lexer) {

    char c;
    int n;
    char *currentToken = "";
    FILE *fp = fopen(lexer->file, "r");

    if (fp == NULL) {
        fprintf(stderr, "No file given");
        exit(-1);
    }

    printf("hello");

    while ((n = fgetc(fp)) != EOF) {
        c = (char)n;
        if (c != ' ' && c != '(') {


        } else {
            printf("%s", currentToken);
            currentToken = "";
        }

    }

    return 1;
}


struct Ha_Token getNextToken(char *line) {



}




