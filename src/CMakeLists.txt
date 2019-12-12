cmake_minimum_required(VERSION 3.15)
project(hawk)
add_executable(hawk main.c compiler/lexer.c compiler/lexer.h collections/c_list.c collections/c_list.h collections/stack.c collections/stack.h collections/t_list.c collections/t_list.h)
