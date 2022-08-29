//
// Created by shiby on 22-8-27.
//
#include <stdio.h>
#include <string.h>
#include "sequence_stack.h"

void parenthesis_match(char str[]) {
    STACK sequence_stack;
    STACK *pstack = &sequence_stack;
    init(pstack);

//    char str[100] = "{{{}}}";
    size_t size = strlen(str);
    for (int i = 0; i < size; i++) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
            push(pstack, str[i]);
            continue;
        }
        if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            datatype d = pop(pstack);

            printf("parenthesis matched %c%c\n", d, str[i]);
            continue;
        }
        printf("skip char %c \n", str[i]);
    }
    if (!empty(pstack))
    {
        printf("this parenthesis match error\n");
    }

}