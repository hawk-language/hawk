#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "../collections/c_list.h"
#include "../collections/t_list.h"
#include "token.h"

// Functions for generating a new lexer

Lexer
new_Lexer(char* file) {
    Lexer lexer;
    lexer.file = file;
    lexer.clist = new_List();
    lexer.clist->append = _list_append;
    lexer.clist->printList = _c_printList;

    lexer.tlist = new_Token_List();
    lexer.tlist->t_append = _t_append;
    lexer.tlist->t_printList = _t_printList;

    lexer.lex = _lexing;
    lexer.eval_List = _evaluate_List;
    lexer.lexer_inputFile = _lexer_fileInput;
    return lexer;
}

// The main function of the lexer, which calls other functions

int
_lexing(struct Ha_Lexer* lexer) {

    lexer->lexer_inputFile(lexer);
    lexer->eval_List(lexer);

    //lexer->tlist->t_printList(lexer->tlist); // FIXME: is throwing seg fault

    return 1;
}

// Function for saving the file, given as input, to the lexers file member, as character list

int
_lexer_fileInput(struct Ha_Lexer* lexer) {

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

int
_evaluate_List(struct Ha_Lexer* lexer) {

    Node* list = lexer->clist->head;
    static const struct Ha_Token Empty;
    struct Ha_Token currentToken;
    enum Ha_Tokens currentEnum;
    currentToken.value = new_List();

    while (list->next != NULL) {

        if (isSeperator(list->value)) {

            if (isSingleToken(list->value)) {

                if (isEmpty(currentToken.value)) {

                    currentEnum = getTokenFromValue(&list->value);
                    currentToken.value->append(currentToken.value, list->value);
                    currentToken.tk = currentEnum;
                    _t_append(lexer->tlist, currentToken);
                    currentToken = Empty;
                    currentToken.value = new_List();

                } else {

                    char *s = _c_ListToString(currentToken.value);
                    currentEnum = getTokenFromValue(s);
                    currentToken.tk = currentEnum;
                    _t_append(lexer->tlist, currentToken);
                    currentToken = Empty;
                    currentToken.value = new_List();

                    currentEnum = getTokenFromValue(&list->value);
                    currentToken.value->append(currentToken.value, list->value);
                    currentToken.tk = currentEnum;
                    _t_append(lexer->tlist, currentToken);
                    currentToken = Empty;
                    currentToken.value = new_List();

                }
            } else {

                printf("SPACE");

            }

        } else {

            currentToken.value->append(currentToken.value, list->value);

        }

        list = list->next;
    }

    return 1;

}

int
isSeperator(char value) {

    int isSep = 0;

    if (value == ' ' || value == '\n' || isSingleToken(value)) {
        isSep = 1;
    }

    return isSep;

}

int
isSingleToken(char value) {

    int isSingleToken = 0;

    if (value == '(' || value == ')' || value == '{' || value == '}' || value == '[' || value == ']'  || value == '+'  || value == '-'  || value == '*'
    || value == '/'  || value == '^'  || value == '%'  || value == '.'  || value == ':'  || value == ';' || value == '=') {

        isSingleToken = 1;

    }

    return isSingleToken;

}

enum Ha_Tokens
getTokenFromValue(char *value) {

    // todo: to for all tokens

    if (strlen(value) > 1) {

        if (!strcmp(value, "func")) {
            return KW_FUNC;
        } else if (!strcmp(value, "if")) {
            return KW_IF;
        } else if (!strcmp(value, "else")) {
            return KW_ELSE;
        } else if (!strcmp(value, "for")) {
            return KW_FOR;
        } else if (!strcmp(value, "do")) {
            return KW_DO;
        } else if (!strcmp(value, "while")) {
            return KW_WHILE;
        } else if (!strcmp(value, "int")) {
            return KW_INT;
        } else if (!strcmp(value, "str")) {
            return KW_STR;
        } else if (!strcmp(value, "double")) {
            return KW_DOUBLE;
        } else if (!strcmp(value, "char")) {
            return KW_CHAR;
        } else {
            return IDENTIFIER;
        }

    } else {

        switch ((int) value) {

            case '(': return OPEN_PAREN;
            case ')': return CLOSE_PAREN;
            case '[': return OPEN_BRACK;
            case ']': return CLOSE_BRACK;
            case '{': return OPEN_CURL;
            case '}': return OPEN_CURL;
            case ';': return SEMICOLON;
            case ':': return COLON;
            case ',': return COMMA;
            case '.': return DOT;
            case '+': return M_PLUS;
            case '-': return M_MINUS;
            case '*': return M_MULTI;
            case '/': return M_DIV;
            case '^': return M_CIRC;
            default: return NONE;

        }

    }

}

int isKeyword(char *value) {

    // todo: write the function out


}