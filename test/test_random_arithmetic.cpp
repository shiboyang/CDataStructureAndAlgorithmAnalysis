//
//
// Created by shiby on 22-9-20.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int random_number(int minInt = 0, int maxInt = 100);

class Expression {
private:
	int num1;
	int num2;
	char sign;
	int result;

public:
	Expression(int n1, int n2, char sign)
			:num1(n1), num2(n2), sign(sign), result(0) { }

	Expression()
	{
		num1 = random_number();
		num2 = random_number(0, 100-num1);
		sign = random_number(0, 2) ? '+' : '-';
		result = (sign=='+' ? num1+num2 : num1-num2);
	}

	friend ostream& operator<<(ostream& os, const Expression& expr)
	{
		cout << expr.num1 << expr.sign << expr.num2 << "=";
		return os;
	}

	int check(int r)
	{
		return r==this->result ? 1 : 0;
	}

};

struct examination{
	Expression * exp;

};

int random_number(int minInt, int maxInt)
{
	return rand()%maxInt;
}

void clean_stdin()
{
	while (getchar()!='\n')
		continue;
}

int main()
{
	srand((unsigned int)time(nullptr));
	Expression expression_list[10];
	int user_result;
	for (auto e : expression_list) {
		cout << e;
		cin >> user_result;
		if (e.check(user_result))
			cout << "correct" << endl;
		else
			cout << "incorrect" << endl;
		clean_stdin();
	}

}