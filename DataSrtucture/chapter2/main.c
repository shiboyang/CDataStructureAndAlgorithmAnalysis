//
// Created by shiby on 22-8-27.
//

#include <stdio.h>
#include "parenthesis_matching.h"

int main(void) {
    char str[100] = "5+(1-100)*[(1+1)-2*(1-1)+{(1+1)+[2-4]}]";
    parenthesis_match(str);
    return 0;
}