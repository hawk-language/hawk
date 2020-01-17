//
// Created by lockna on 1/17/20.
//

#include <hawk/symtable.h>
#include <stdlib.h>
#include <stdio.h>

int append(struct SymTable *table, struct SymTableEntry entry) {

    if (table->head == NULL) {

        table->head = malloc(sizeof(struct SymTableEntry));
        table->head->type = entry.type;
        table->head->scope = entry.scope;
        table->head->identifier = entry.identifier;

        table->head->next = NULL;
        table->head->prev = NULL;
        table->tail = table->head;

    } else {

        struct SymTableEntry* new = malloc(sizeof(struct SymTableEntry));

        new->identifier = entry.identifier;
        new->scope = entry.scope;
        new->type = entry.type;

        new->next = NULL;
        new->prev = table->tail;
        table->tail->next = new;
        table->tail = new;

    }

}

void printSymTable(struct SymTable *table) {

    struct SymTableEntry* head = table->head;

    while (head != NULL) {

        printf("%s %s %s\n", head->type, head->scope, head->identifier);

        head = head->next;

    }

}
