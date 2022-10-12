//
// Created by shiby on 22-10-9.
//

#include "lib.h"
#include <algorithm>
#include <iterator>
#include <cmath>

bool all_zero(vector<int>& v)
{
	auto ptr = std::find_if(v.begin(), v.end(), [](int i) { return i!=0; });
	return ptr!=v.end();
}

void print_vector(vector<int>& v, char sign, bool reverse, int output_base)
{
	int residue = 0;
	vector<int> num_list(v.rbegin(), v.rend());
	vector<char> ret_v;
	if (reverse) {
		while (all_zero(num_list)) {
			for (int& num : num_list) {
				num += residue*10;
				residue = num%output_base;
				num /= output_base;
			}
			ret_v.push_back(number_to_char(residue));
			residue = 0;
		}
		if (!ret_v.empty()) {
			if (sign=='-') std::cout << sign;
			for (auto j = ret_v.rbegin(); j<ret_v.rend(); ++j) {
				std::cout << *j;
			}
		}
	}
}

char number_to_char(int num)
{
	if (num<=9)
		return char('0'+num);
	else if (num<=36)
		return char('a'+num-10);
	else {
		cout << "Conversion Failed" << endl;
		exit(EXIT_FAILURE);
	}
}

/*!
 * Convert a character to a number greater than 0
 * Conversion failure return -1
 */
int to_digit(char ch)
{
	if (ch>='0' && ch<='9') {
		return ch-'0';
	}
	else if (ch>='a' && ch<='z') {
		return ch-'a'+10;
	}
	else if (ch>='A' && ch<='Z') {
		return ch-'A'+10;
	}
	else
		return -1;
}

int calculate(int n1, int n2, char sign)
{
	return (sign=='-') ? n1-n2 : n1+n2;
}

vector<int> operate_vector(vector<int>& v1, vector<int>& v2, char sign = '+')
{
	vector<int> result_list;
	const int base = 10;
	istringstream iss;
	int b = 0;
	while (true) {
		auto num1 = v1.empty() ? 0 : v1.back();
		auto num2 = v2.empty() ? 0 : v2.back();
		auto sum = calculate(num1, num2, sign)+b;

		if (sum>base) {
			result_list.push_back(sum-base);
			b = 1;
		}
		else {
			if (sum<0) {
				sum += base;
				b = -1;
			}
			else
				b = 0;
			result_list.push_back(sum);
		}
		if (!v1.empty()) v1.pop_back();
		if (!v2.empty()) v2.pop_back();
		if (v1.empty() && v2.empty()) break;
	}
	return std::move(result_list);
}

bool is_operator(char ch)
{
	return ch=='-' || ch=='+';
}

bool verify_input_line(string_view sv, int base)
{
	auto begin = sv.begin();
	if (is_operator(*begin)) begin++;
	auto all_digit = [base](char ch) {
		auto num = to_digit(ch);
		return num!=-1 && num<base;
	};
	auto find_ptr = std::find_if_not(begin, sv.end(), all_digit);
	return find_ptr==sv.end();
}

vector<int> string2vector(string_view sv)
{
	vector<int> ret;
	auto begin = sv.begin();
	if (is_operator(sv[0])) begin++;
	string_view sv2(begin);
	auto pos = sv2.find_first_not_of('0');
	for (auto i = sv2.begin()+pos; i<sv2.end(); i++) {
		ret.push_back(to_digit(*i));
	}
	return std::move(ret);
}






