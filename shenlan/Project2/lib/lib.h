//
// Created by shiby on 22-10-9.
//

#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string_view>

using namespace std;

vector<int> string2vector(const string &s, int base);


vector<int> operate_vector(vector<int> &v1, vector<int> &v2, char sign);


int calculate(int n1, int n2, char sign);

int to_digit(char ch);

char number_to_char(int num);


void print_vector(vector<int> &v, char sign, bool reverse, int output_base);


bool verify_input_line(string_view sv, int base);

bool is_operator(char ch);

vector<int> string2vector(string_view sv);


#endif //TEST_LIB_H
