#include <stdlib.h>
#include <string.h>
#include <hawk/lexer.h>
#include <hawk/c_list.h>
#include <hawk/t_list.h>
#include <hawk/token.h>

// Functions for generating a new lexer

Lexer
new_Lexer(char* file) {
    Lexer lexer;
    // FIXME: in cloning not recognizing the file
    sprintf(lexer.file, "../%s", file);
    //lexer.file = file;
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

    //lexer->tlist->t_printList(lexer->tlist);

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
    // FIXME: last two closing curly braces aren't in token list
    Node* list = lexer->clist->head;
    static const struct Ha_Token Empty;
    struct Ha_Token currentToken;
    enum Ha_Tokens currentEnum;
    currentToken.value = new_List();

    while (list != NULL) {

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

                if (!isEmpty(currentToken.value)) {

                    char *s = _c_ListToString(currentToken.value);
                    currentEnum = getTokenFromValue(s);
                    currentToken.tk = currentEnum;
                    _t_append(lexer->tlist, currentToken);
                    currentToken = Empty;
                    currentToken.value = new_List();

                }
            }

        } else {
            currentToken.value->append(currentToken.value, list->value);
        }
        list = list->next;
    }
    _t_printList(lexer->tlist);
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

    enum Ha_Tokens token;

    if (isKeyword(value, &token)) {
        return token;
    } else if(isNumber(value)) {
        return NUMBER;
    } else {
        if (strlen(value) == 1) {

            switch (*value) {
                case '(': return OPEN_PAREN;
                case ')': return CLOSE_PAREN;
                case '[': return OPEN_BRACK;
                case ']': return CLOSE_BRACK;
                case '{': return OPEN_CURL;
                case '}': return CLOSE_CURL;
                case ';': return SEMICOLON;
                case ':': return COLON;
                case ',': return COMMA;
                case '.': return DOT;
                case '+': return M_PLUS;
                case '-': return M_MINUS;
                case '*': return M_MULTI;
                case '/': return M_DIV;
                case '^': return M_CIRC;
                case '=': return OP_EQUAL;
                case '<': return OP_LT;
                case '>': return OP_GT;
                default: return IDENTIFIER;
            }
        } else {
            return IDENTIFIER;
        }
    }
}

int
isNumber(char *value) {

    int isNum = 1;
    int i = 0;

    while (value[i] != '\0' && isNum) {
        if (!(value[i] >= 48 && value[i] <= 57)) {
            isNum = 0;
        }
        i += 1;
    }

    return isNum;

}

int
isKeyword(char *value, enum Ha_Tokens* token) {

    int isKW = 1;

    if (!strcmp(value, "func")) {
        *token = KW_FUNC;
    } else if (!strcmp(value, "if")) {
        *token = KW_IF;
    } else if (!strcmp(value, "else")) {
        *token = KW_ELSE;
    } else if (!strcmp(value, "for")) {
        *token = KW_FOR;
    } else if (!strcmp(value, "do")) {
        *token = KW_DO;
    } else if (!strcmp(value, "while")) {
        *token = KW_WHILE;
    } else if (!strcmp(value, "int")) {
        *token = KW_INT;
    } else if (!strcmp(value, "str")) {
        *token = KW_STR;
    } else if (!strcmp(value, "double")) {
        *token = KW_DOUBLE;
    } else if (!strcmp(value, "struct")) {
        *token = KW_STRUCT;
    } else if (!strcmp(value, "union")) {
        *token = KW_UNION;
    } else if (!strcmp(value, "class")) {
        *token = KW_CLASS;
    } else {
        isKW = 0;
    }
    return isKW;
}