//
// Created by shiby on 22-8-27.
//
#include <stdio.h>
#include <string.h>
#include "sequence_stack.h"

void parenthesis_match(char str[])
{
	STACK sequence_stack;
	STACK* pstack = &sequence_stack;
	init(pstack);

//    char str[100] = "{{{}}}";
	size_t size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		switch (str[i])
		{
		case '{':
		case '(':
		case '[':
			push(pstack, str[i]);
			break;
		case '}':
		{
			datatype d = pop(pstack);
			if (d != '{')
				printf("error matching: %c and }\n", d);
			else
				printf("matched %c and %c\n", d, '}');
			break;
		}
		case ')':
		{
			datatype d = pop(pstack);
			if (d != '(')
				printf("error matching: %c and )\n", d);
			else
				printf("matched %c and %c\n", d, ')');
			break;
		}
		case ']':
		{
			datatype d = pop(pstack);
			if (d != '[')
				printf("error matching: %c and ]\n", d);
			else
				printf("matched %c and %c\n", d, ']');
			break;
		}
		default:
			printf("skip char %c \n", str[i]);
		}
	}
	if (!empty(pstack))
	{
		printf("this parenthesis match error\n");
	}

}