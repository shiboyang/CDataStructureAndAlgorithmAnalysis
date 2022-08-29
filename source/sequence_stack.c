//
// Created by shiby on 22-8-27.
//

#include "sequence_stack.h"
#include <stdio.h>


void init(STACK * pst)
{
    pst->top = 0;
}

int empty(STACK * pst)
{
    return pst->top ? 0 : 1;
}

datatype read(STACK * pst)
{
    return pst->data[pst->top];
}

void push(STACK * pst, datatype data)
{
    if (pst->top > MAXSIZE)
    {
        printf("Stack is full");
        return;
    }
    pst->data[pst->top] = data;
    pst->top++;
}

datatype pop(STACK * pst)
{
    datatype tmp;
    tmp = pst->data[pst->top-1];
    pst->top--;
    return tmp;
}
