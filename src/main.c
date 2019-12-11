//
// Created by lockna on 11/28/19.
//
#include "compiler/lexer.h"
#include "collections/c_list.h"

int main(int argc, char *argv[]) {
    Lexer le = initialize_lex("../test.hk");
    List* lst = new_List();
    lex(&le, lst);


    printList(lst);
}
