#include <stdlib.h>
#include <string.h>
#include <hawk/lexer.h>
#include <hawk/token_list.h>
#include <hawk/token.h>

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
        token_printList(lexer->t_list);

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
                        token_append(lexer->t_list, makeToken(",", COMMA, line));
                else if (lexer->buffer[i] == '.')
                        token_append(lexer->t_list, makeToken(".", DOT, line));
                else if (lexer->buffer[i] == ':')
                        token_append(lexer->t_list, makeToken(":", COLON, line));
                else if (lexer->buffer[i] == ';')
                        token_append(lexer->t_list, makeToken(";", SEMICOLON, line));
                else if (lexer->buffer[i] == '(')
                        token_append(lexer->t_list, makeToken("(", OPEN_PAREN, line));
                else if (lexer->buffer[i] == ')')
                        token_append(lexer->t_list, makeToken(")", CLOSE_PAREN, line));
                else if (lexer->buffer[i] == '{')
                        token_append(lexer->t_list, makeToken("{", OPEN_CURL, line));
                else if (lexer->buffer[i] == '}')
                        token_append(lexer->t_list, makeToken("}", CLOSE_CURL, line));
                else if (lexer->buffer[i] == '[')
                        token_append(lexer->t_list, makeToken("[", OPEN_BRACK, line));
                else if (lexer->buffer[i] == ']')
                        token_append(lexer->t_list, makeToken("]", CLOSE_CURL, line));
                else if (lexer->buffer[i] == '*')
                        token_append(lexer->t_list, makeToken("*", STAR, line));
                else if (lexer->buffer[i] == '^')
                        token_append(lexer->t_list, makeToken("^", CIRC, line));
                else if (lexer->buffer[i] == '%')
                        token_append(lexer->t_list, makeToken("%", MOD, line));
                else if (lexer->buffer[i] == '\n')
                        line += 1;
                else if (lexer->buffer[i] == ' ' || lexer->buffer[i] == '\t' || lexer->buffer[i] == '\r') {

                } else if (lexer->buffer[i] == '+' && lexer->buffer[i + 1] == '+') {

                        token_append(lexer->t_list, makeToken("++", PLUS_PLUS, line));
                        i += 1;

                } else if (lexer->buffer[i] == '+') {

                        token_append(lexer->t_list, makeToken("+", PLUS, line));

                } else if (lexer->buffer[i] == '-' && lexer->buffer[i + 1] == '-') {

                        token_append(lexer->t_list, makeToken("--", MINUS_MINUS, line));
                        i += 1;

                } else if (lexer->buffer[i] == '-') {

                        token_append(lexer->t_list, makeToken("-", MINUS, line));

                } else if (lexer->buffer[i] == '&' && lexer->buffer[i + 1] == '&') {

                        token_append(lexer->t_list, makeToken("&&", AND, line));
                        i += -1;

                } else if (lexer->buffer[i] == '|' && lexer->buffer[i + 1] == '|') {

                        token_append(lexer->t_list, makeToken("||", OR, line));
                        i += 1;

                } else if (lexer->buffer[i] == '!' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken("!=", BANG_EQUAL, line));
                        i += 1;

                } else if (lexer->buffer[i] == '!') {

                        token_append(lexer->t_list, makeToken("!", BANG, line));

                } else if (lexer->buffer[i] == '=' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken("==", EQUAL_EQUAL, line));
                        i += 1;

                } else if (lexer->buffer[i] == '=') {

                        token_append(lexer->t_list, makeToken("=", EQUAL, line));

                } else if (lexer->buffer[i] == '>' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken(">=", GREATER_EQUAL, line));
                        i += 1;

                } else if (lexer->buffer[i] == '>') {

                        token_append(lexer->t_list, makeToken(">", GREATER, line));

                } else if (lexer->buffer[i] == '<' && lexer->buffer[i + 1] == '=') {

                        token_append(lexer->t_list, makeToken("<=", LESS_EQUAL, line));
                        i += 1;

                } else if (lexer->buffer[i] == '<') {

                        token_append(lexer->t_list, makeToken("<", LESS, line));

                } else if (lexer->buffer[i] == '/' && lexer->buffer[i + 1] == '/') {

                        while (lexer->buffer[i] != '\n') {
                                i += 1;
                        }

                        line += 1;

                } else if (lexer->buffer[i] == '/') {
                        token_append(lexer->t_list, makeToken("/", SLASH, line));
                } else {

                        if (isDigit(lexer->buffer[i])) {

                                token_append(lexer->t_list, number(lexer->buffer, &i));

                        } else if (isAlpha(lexer->buffer[i])) {


                        }

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
                printf("hierasdf\n");
                return makeToken("Unexpected DOT", ERR, line);
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


        return makeToken(num, NUMBER, line);


}

static char *string(char *buffer)
{


}

static char *checkKeyword(char *buffer)
{

}

static struct Token makeToken(char *value, int tok, int line)
{

        struct Token token;
        token.TokenType = tok;
        token.linenumber = line;
        token.value = value;

        return token;

}













