//
// Created by lockna on 3/25/20.
//

#ifndef HAWK_AST_H
#define HAWK_AST_H

enum AST_Node_Type {

    AST_Node_Type_Number,
    AST_Node_Type_Variable,
    AST_Node_Type_BinExpr,
    AST_Node_Type_Call,
    AST_Node_Type_Prototype,
    AST_Node_Type_Function,
    AST_Node_Type_IF
};

enum AST_BinExpr_Operator {

    PLUS, MINUS, MUL, DIV

};

struct AST_Number {
    double value;
};

struct AST_Variable {
    char *name;
};

struct AST_BinExpr {

    enum AST_BinExpr_Operator operator;
    struct AST_Node *left;
    struct AST_Node *right;

};

struct AST_Call {

    char *name;
    char **args;
    unsigned short arg_count;

};

struct AST_Prototype {

    char *name;
    char **args;
    unsigned short arg_count;
    struct AST_Node *type_return;

};

struct AST_Function {

    struct AST_Node *prototype;
    struct AST_Node *body;
    struct AST_Node *type_return;

};

struct AST_IF {

    struct AST_Node *condition;
    struct AST_Node *then_expr;
    struct AST_Node *else_expr;

};

struct AST_Node {

    enum AST_Node_Type type;

    union {

        struct AST_Number number;
        struct AST_Variable variable;
        struct AST_BinExpr binexpr;
        struct AST_Call call;
        struct AST_Prototype prototype;
        struct AST_Function function;
        struct AST_IF if_expr;

    };

};


struct AST {

    struct AST_Node *TopNode;

};

#endif //HAWK_AST_H
