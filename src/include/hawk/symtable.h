//
// Created by lockna on 1/17/20.
//

#ifndef HAWK_SYMTABLE_H
#define HAWK_SYMTABLE_H

struct SymTableEntry {

    char* scope;
    char* identifier;
    char* type;

    struct SymTableEntry* next;
    struct SymTableEntry* prev;

};

struct SymTable {

    struct SymTableEntry* head;
    struct SymTableEntry* tail;
    int length;

};

int append(struct SymTable *table, struct SymTableEntry entry);
void printSymTable(struct SymTable *table);

#endif //HAWK_SYMTABLE_H
