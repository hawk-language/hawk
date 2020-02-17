#include <stdlib.h>
#include <string.h>
#include <hawk/lexer.h>
#include <hawk/c_list.h>
#include <hawk/t_list.h>
#include <hawk/token.h>

// Functions for generating a new lexer

struct Lexer new_Lexer(char *file)
{
        struct Lexer lexer;
        lexer.file = file;
        lexer.c_list = new_List();
        lexer.t_list = new_Token_List();

        return lexer;
}

// The main function of the lexer, which calls other functions

int lexing(struct Lexer *lexer)
{
        // todo: preprocessor (imports)
        // FIXME: == is recognized as two seperate =

        lexer_fileInput(lexer);
        evaluate_List(lexer);

        t_printList(lexer->t_list);

        return 0;
}

// Function for saving the file, given as input, to the lexers file member, as character list

static int lexer_fileInput(struct Lexer *lexer)
{
        char c;
        FILE *fp = fopen(lexer->file, "r");

        if (fp == NULL) {
                fprintf(stderr, "No file given");
                exit(-1);
        }

        while ((c = fgetc(fp)) != EOF) {
                list_append(lexer->c_list, c);
        }
        return 0;

}

// Function that evaluates the list from the lexer and saves the tokens to the token list from the lexer

static int evaluate_List(struct Lexer *lexer)
{
        struct char_node *list = lexer->c_list->head;
        static const struct Token Empty;
        struct Token currentToken;
        int currentEnum;
        currentToken.value = new_List();

        while (list != NULL) {

                if (isSeperator(list->value)) {

                        if (isSingleToken(list->value)) {

                                if (isEmpty(currentToken.value)) {

                                        currentEnum = getTokenFromValue(&list->value);
                                        list_append(currentToken.value, list->value);
                                        currentToken.tk = currentEnum;
                                        t_append(lexer->t_list, currentToken);

                                        currentToken = Empty;
                                        currentToken.value = new_List();

                                } else {

                                        char *s = c_ListToString(currentToken.value);
                                        currentEnum = getTokenFromValue(s);
                                        currentToken.tk = currentEnum;
                                        t_append(lexer->t_list, currentToken);
                                        currentToken = Empty;
                                        currentToken.value = new_List();

                                        currentEnum = getTokenFromValue(&list->value);
                                        list_append(currentToken.value, list->value);
                                        currentToken.tk = currentEnum;
                                        t_append(lexer->t_list, currentToken);
                                        currentToken = Empty;
                                        currentToken.value = new_List();
                                }

                        } else {

                                if (!isEmpty(currentToken.value)) {

                                        char *s = c_ListToString(currentToken.value);
                                        currentEnum = getTokenFromValue(s);
                                        currentToken.tk = currentEnum;
                                        t_append(lexer->t_list, currentToken);
                                        currentToken = Empty;
                                        currentToken.value = new_List();

                                }
                        }

                } else {
                        list_append(currentToken.value, list->value);
                }
                list = list->next;
        }
        return 0;
}

static int isSeperator(char value)
{
        int isSep = 0;

        if (value == ' ' || value == '\n' || isSingleToken(value)) {
                isSep = 1;
        }

        return isSep;

}

static int isSingleToken(char value)
{

        int isSingleToken = 0;

        if (value == '(' || value == ')' || value == '{' || value == '}' || value == '[' || value == ']' ||
            value == '+' ||
            value == '-' || value == '*'
            || value == '/' || value == '^' || value == '%' || value == '.' || value == ':' || value == ';' || value == '=') {
                isSingleToken = 1;
        }

        return isSingleToken;

}

static enum Ha_Tokens getTokenFromValue(char *value)
{

        int token;

        if (isKeyword(value, &token)) {
                return token;
        } else if (isNumber(value)) {
                return NUMBER;
        } else if (value[0] == '"' && value[strlen(value) - 1] == '"') {
                return STRING_LITERAL;
        } else {
                if (strlen(value) == 1) {

                        switch (*value) {
                        case '(':
                                return OPEN_PAREN;
                        case ')':
                                return CLOSE_PAREN;
                        case '[':
                                return OPEN_BRACK;
                        case ']':
                                return CLOSE_BRACK;
                        case '{':
                                return OPEN_CURL;
                        case '}':
                                return CLOSE_CURL;
                        case ';':
                                return SEMICOLON;
                        case ':':
                                return COLON;
                        case ',':
                                return COMMA;
                        case '.':
                                return DOT;
                        case '+':
                                return M_PLUS;
                        case '-':
                                return M_MINUS;
                        case '*':
                                return M_MULTI;
                        case '/':
                                return M_DIV;
                        case '^':
                                return M_CIRC;
                        case '=':
                                return OP_EQUAL;
                        case '<':
                                return OP_LT;
                        case '>':
                                return OP_GT;
                        default:
                                return IDENTIFIER;
                        }
                } else {
                        return IDENTIFIER;
                }
        }
}

static int isNumber(const char *value)
{

        int isNum = 1;
        int i = 0;

        while (value[i] != '\0' && isNum) {
                if (value[i] > '9' || value[i] < '0') {
                        isNum = 0;
                }
                i += 1;
        }

        return isNum;

}

static int isKeyword(char *value, int *token)
{

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
