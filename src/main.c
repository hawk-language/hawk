//
// Created by lockna on 11/28/19.
//
#include <hawk/lexer.h>
#include <hawk/symtable.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    setbuf(stdout, NULL);
    Lexer lexer = new_Lexer(argv[1]);
    lexer.lex(&lexer);

    struct SymTable* table = malloc(sizeof(struct SymTable));
    struct SymTableEntry entry;
    entry.identifier = "a";
    entry.type = "int";
    entry.scope = "global";

    append(table, entry);

    printSymTable(table);

    return 0;
}
