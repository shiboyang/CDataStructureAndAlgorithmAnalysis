//
// Created by shiby on 22-8-30.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "expression_evaluation.h"
#include "sequence_stack.h"

#define IS_NUMBER(x) '0'<=(x) && (x)<='9'
#define IS_SPOT(x) (x) == '.'
#define IS_SPACE(x) (x) == ' '

static void infix_to_postfix(char [], char []);
static bool is_operation(char);
static float evaluate_postfix_expression(char []);
static int priority(char);
static double string_to_number(char []);
static double evaluate(double num1, double num2, char operator);

static double string_to_number(char str[])
{
	double number = 0.0;
	double i = 1.0;
	while (*str)
	{
		if (IS_NUMBER(*str))
		{
			if (i > 0)
				number = number * 10 + (*str - '0');
			else
				number = number + pow(10.0, i--) * (*str - '0');
		}
		else if (IS_SPOT(*str))
			i = -1.0;
		str++;
	}

	return number;
}

double evaluate(double num1, double num2, char operator)
{
	switch (operator)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	default:
		printf("invalid operator! %c", operator);
		exit(-1);
	}
}

double evaluate_expression(char str[])
{
	char postfix_str[100];
	char tmp_str[100];
	int i = 0, m = 0, n = 0;
	double num_array[100];
	double num;

	infix_to_postfix(str, postfix_str);

	while (postfix_str[n])
	{
		if (IS_NUMBER(postfix_str[n]) || IS_SPOT(postfix_str[n]))
			tmp_str[i++] = postfix_str[n];
		else if (IS_SPACE(postfix_str[n]))
		{
			if (i == 0) goto end;
			tmp_str[i] = '\0';
			num_array[m++] = string_to_number(tmp_str);
			i = 0;
		}
		else if (is_operation(postfix_str[n]))
		{
			num = evaluate(num_array[m - 2], num_array[m - 1], postfix_str[n]);
			num_array[m - 2] = num;
			num_array[m - 1] = 0;
			m--;
		}
		else
			continue;

	end: n++;
	}

	return num_array[0];
}

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
	tmp_str[i++] = '\0';
	printf("%s\n", tmp_str);
	strcpy(s2, tmp_str);
}

int main(void)
{
//	char str[100] = "0.3/(5*2+1)#";
	char str[100] = "1*20*(2-19/(2+3))#";
	double num = evaluate_expression(str);
	printf("Result: %lf\n", num);
	return 0;
}