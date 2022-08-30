//
// Created by shiby on 22-8-30.
//

#include <stdbool.h>
#include <stdio.h>
#include "expression_evaluation.h"
#include "sequence_stack.h"

#define IS_NUMBER(x) '0'<=(x) && (x)<='9'
#define IS_SPOT(x) (x) == '.'

static void infix_to_postfix(char [], char []);

static bool is_operation(char);

static float evaluate_postfix_expression(char []);

static int priority(char);

static int priority(char c)
{
	switch (c)
	{
	case '#':
		return -1;
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}

static float string_to_number(char []);

static float string_to_number(char str[])
{

}

float evaluate_expression(char str[])
{
	float result = 0.0f;
	char postfix_str[100];

	infix_to_postfix(str, postfix_str);

	return result;
}

//后缀表达式转中缀表达式
static void infix_to_postfix(char str[], char s2[])
{
	char tmp_str[100];
	int i = 0;
	STACK operator_stack;
	init(&operator_stack);
	char c;

	while (*str != '#')
	{
		if (IS_NUMBER(*str) || IS_SPOT(*str))
		{
			tmp_str[i] = *str;
			i++;
		}
		else if (*str == '(')
		{
			push(&operator_stack, *str);
		}
		else if (*str == ')')
		{
			while (read(&operator_stack) != '(')
			{
				tmp_str[i++] = ' ';
				tmp_str[i++] = pop(&operator_stack);
				tmp_str[i++] = ' ';

			}
			pop(&operator_stack);
		}
		else if (is_operation(*str))
		{
			tmp_str[i++] = ' ';
			while (priority(*str) <= priority(read(&operator_stack)))
			{

				tmp_str[i++] = pop(&operator_stack);
				tmp_str[i++] = ' ';
			}
			if (priority(*str) > priority(read(&operator_stack)))
				push(&operator_stack, *str);
		}
		else
			printf("invalid  char %c\n", *str);
		str++;
	}
	while (!empty(&operator_stack))
	{
		tmp_str[i++] = pop(&operator_stack);
		tmp_str[i++] = ' ';

	}
	printf("%s", tmp_str);
}

//判断是否操作符
static bool is_operation(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}


int main(void) {
	char str[100] = "0.3/(5*2+1)#";
	evaluate_expression(str);
	return 0;
}