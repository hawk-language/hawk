//
// Created by lockna on 3/26/20.
//

#include <stdlib.h>
#include <string.h>
#include <hawk/lexer.h>
#include <hawk/token_list.h>
#include <hawk/token.h>

static char *lexer_readFile(const char *path);
static int evaluate_File(struct Lexer *lexer);
static int isDigit(char value);
static int isAlpha(char c);
static struct Token checkKeyword(char *buffer, int *current);
static char *getNextAlpha(char *buffer, int *current);
static struct Token number(char *buffer, int *current);
static struct Token string(const char *buffer, int *current);
static struct Token makeToken(char *value, int tok);


// Functions for generating a new lexer

int line = 1;

struct Lexer new_Lexer(char *path)
{
        struct Lexer lexer;
        lexer.path = path;
        lexer.t_list = new_Token_List();
        lexer.buffer = lexer_readFile(path);
        return lexer;
}

// The main function of the lexer, which calls other functions

int lexing(struct Lexer *lexer)
{
        // todo: preprocessor (imports)

        evaluate_File(lexer);
        //token_printList(lexer->t_list);

        return 0;
}

// Function for saving the file, given as input, to the lexers file member, as
// char buffer

static char *lexer_readFile(const char *path)
{
        FILE *file = fopen(path, "rb");
//> no-file
        if (file == NULL) {
                fprintf(stderr, "Could not open file \"%s\".\n", path);
                exit(74);
        }
//< no-file

        fseek(file, 0L, SEEK_END);
        size_t fileSize = ftell(file);
        rewind(file);

        char *buffer = malloc(fileSize + 1);
//> no-buffer
        if (buffer == NULL) {
                fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
                exit(74);
        }

//< no-buffer
        size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
//> no-read
        if (bytesRead < fileSize) {
                fprintf(stderr, "Could not read file \"%s\".\n", path);
                exit(74);
        }

//< no-read
        buffer[bytesRead] = '\0';

        fclose(file);
        return buffer;
}

// Function that evaluates the list from the lexer and saves the tokens to the
// token list from the lexer

static int evaluate_File(struct Lexer *lexer)
{

        int i = 0;

        while (lexer->buffer[i] != '\0') {

                if (lexer->buffer[i] == ',')
                        token_append(lexer->t_list, makeToken(",", COMMA));
                else if (lexer->buffer[i] == '.')
                        token_append(lexer->t_list, makeToken(".", DOT));
                else if (lexer->buffer[i] == ':')
                        token_append(lexer->t_list, makeToken(":", COLON));
                else if (lexer->buffer[i] == ';')
                        token_append(lexer->t_list, makeToken(";", SEMICOLON));
                else if (lexer->buffer[i] == '(')
                        token_append(lexer->t_list, makeToken("(", OPEN_PAREN));
                else if (lexer->buffer[i] == ')')
                        token_append(lexer->t_list, makeToken(")", CLOSE_PAREN));
                else if (lexer->buffer[i] == '{')
                        token_append(lexer->t_list, makeToken("{", OPEN_CURL));
                else if (lexer->buffer[i] == '}')
                        token_append(lexer->t_list, makeToken("}", CLOSE_CURL));
                else if (lexer->buffer[i] == '[')
                        token_append(lexer->t_list, makeToken("[", OPEN_BRACK));
                else if (lexer->buffer[i] == ']')
                        token_append(lexer->t_list, makeToken("]", CLOSE_CURL));
                else if (lexer->buffer[i] == '*')
                        token_append(lexer->t_list, makeToken("*", STAR));
                else if (lexer->buffer[i] == '^')
                        token_append(lexer->t_list, makeToken("^", CIRC));
                else if (lexer->buffer[i] == '%')
                        token_append(lexer->t_list, makeToken("%", MOD));
                else if (lexer->buffer[i] == '\n')
                        line += 1;
                else if (lexer->buffer[i] == ' ' || lexer->buffer[i] == '\t' || lexer->buffer[i] == '\r') {

                } else if (lexer->buffer[i] == '+' && lexer->buffer[i + 1] == '+') {

                        token_append(lexer->t_list, makeToken("++", PLUS_PLUS));
                        i += 1;

                } else if (lexer->buffer[i] == '+') {

                        token_append(lexer->t_list, makeToken("+", PLUS));

                } else if (lexer->buffer[i] == '-' && lexer->buffer[i + 1] == '-') {

                        token_append(lexer->t_list, makeToken("--", MINUS_MINUS));
                        i += 1;

                } else if (lexer->buffer[i] == '-') {

                        token_append(lexer->t_list, makeToken("-", MINUS));

                } else if (lexer->buffer[i] == '&' && lexer->buffer[i + 1] == '&') {

                        token_append(lexer->t_list, makeToken("&&", AND));
                        i += -1;

                } else if (lexer->buffer[i] == '|' && lexer->buffer[i + 1] == '|') {

                        token_append(lexer->t_list, makeToken("||", OR));
                        i += 1;

                } else if (lexer->buffer[i] == '!' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken("!=", BANG_EQUAL));
                        i += 1;

                } else if (lexer->buffer[i] == '!') {

                        token_append(lexer->t_list, makeToken("!", BANG));

                } else if (lexer->buffer[i] == '=' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken("==", EQUAL_EQUAL));
                        i += 1;

                } else if (lexer->buffer[i] == '=') {

                        token_append(lexer->t_list, makeToken("=", EQUAL));

                } else if (lexer->buffer[i] == '>' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken(">=", GREATER_EQUAL));
                        i += 1;

                } else if (lexer->buffer[i] == '>') {

                        token_append(lexer->t_list, makeToken(">", GREATER));

                } else if (lexer->buffer[i] == '<' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken("<=", LESS_EQUAL));
                        i += 1;

                } else if (lexer->buffer[i] == '<') {

                        token_append(lexer->t_list, makeToken("<", LESS));

                } else if (lexer->buffer[i] == '/' && lexer->buffer[i + 1] == '/') {

                        while (lexer->buffer[i] != '\n') {
                                i += 1;
                        }

                        line += 1;

                } else if (lexer->buffer[i] == '/') {
                        token_append(lexer->t_list, makeToken("/", SLASH));
                } else if (lexer->buffer[i] == '"') {
                        token_append(lexer->t_list, string(lexer->buffer, &i));
                } else if (isDigit(lexer->buffer[i])) {
                        token_append(lexer->t_list, number(lexer->buffer, &i));
                } else if (isAlpha(lexer->buffer[i])) {
                        token_append(lexer->t_list, checkKeyword(lexer->buffer, &i));
                } else {
                        printf("Unknown symbol");
                }


                i += 1;


        }

        return 0;
}

static int isDigit(char buffer)
{
        return buffer >= '0' && buffer <= '9';
}

static int isAlpha(char c)
{
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

static struct Token number(char *buffer, int *current)
{

        int dot = 0;
        int start = *current;

        JMP:
        while (isDigit(buffer[*current]) && buffer[*current] != '\0') *current += 1;


        if (buffer[*current] == '.' && isDigit(buffer[*current + 1])) {
                dot += 1;
                *current += 1;
                goto JMP;
        }

        if (dot == 2) {
                return makeToken("Unexpected DOT", ERR);
        }


        char *num = malloc((*current - start) + 1);
        int i = 0;

        while (start != *current) {
                num[i] = buffer[start];
                i += 1;
                start += 1;

        }

        num[i] = '\0';
        *current -= 1;


        return makeToken(num, NUMBER);


}

static struct Token string(const char *buffer, int *current)
{

        *current += 1;
        int start = *current;

        while (buffer[*current] != '"') {

                if (buffer[*current] == '\0') {
                        return makeToken("Unterminated string", ERR);
                }
                *current += 1;
        }

        char *string = malloc((*current - start) + 1);

        int i = 0;
        while (start != *current) {
                string[i] = buffer[start];
                i += 1;
                start += 1;
        }

        string[i] = '\0';
        return makeToken(string, STRING);


}

static struct Token checkKeyword(char *buffer, int *current)
{

        char *string = getNextAlpha(buffer, current);

        if (!strcmp(string, "struct")) {
                return makeToken("struct", STRUCT);
        } else if (!strcmp(string, "if")) {
                return makeToken("if", IF);
        } else if (!strcmp(string, "else")) {
                return makeToken("else", ELSE);
        } else if (!strcmp(string, "for")) {
                return makeToken("for", FOR);
        } else if (!strcmp(string, "while")) {
                return makeToken("while", WHILE);
        } else if (!strcmp(string, "return")) {
                return makeToken("return", RETURN);
        } else if (!strcmp(string, "import")) {
                return makeToken("import", IMPORT);
        } else if (!strcmp(string, "int")) {
                return makeToken("int", INT);
        } else if (!strcmp(string, "char")) {
                return makeToken("char", CHAR);
        } else if (!strcmp(string, "str")) {
                return makeToken("str", STR);
        } else if (!strcmp(string, "decimal")) {
                return makeToken("decimal", DECIMAL);
        } else if (!strcmp(string, "bool")) {
                return makeToken("bool", BOOL);
        } else {
                return makeToken(string, IDENTIFIER);
        }


}

static struct Token makeToken(char *value, int tok)
{

        struct Token token;
        token.TokenType = tok;
        token.linenumber = line;
        token.value = value;

        return token;

}

static char *getNextAlpha(char *buffer, int *current)
{

        int start = *current;
        while (isAlpha(buffer[*current]) && buffer[*current] != '\0') {
                *current += 1;
        }

        char *string = malloc((*current - start) + 1);

        int i = 0;
        while (start != *current) {
                string[i] = buffer[start];
                i += 1;
                start += 1;
        }
        *current -= 1;
        string[i] = '\0';
        return string;

}