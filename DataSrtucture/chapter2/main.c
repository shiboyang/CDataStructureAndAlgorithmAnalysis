//
// Created by shiby on 22-8-27.
//

#include <stdio.h>
#include "parenthesis_matching.h"
#include "expression_evaluation.h"

int main(void) {
//    char str[100] = "5+(1-100)*[(1+1)-2*(1-1)+{(1+1)+[2-4]}]#";
	char str[100] = "0.3/(5*2+1)#";
	char s2[100];
//    parenthesis_match(str);
	evaluate_expression(str);
	return 0;
}