//
// Created by shiby on 22-9-25.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;


vector<int> string2vector(const string &s, int base);

vector<char> operate_vector(vector<int> &v1, vector<int> &v2, int base, char sign);

int calculate(int n1, int n2, char sign);

void print_vector(vector<int> &v) {
    for (auto i: v) {
        cout << i << endl;
    }
}

void print_result(vector<char> &result) {
    for (size_t i = result.size(); i > 0; --i) {
        cout << result[i - 1];
    }
}


char number_to_char(int num) {
    if (num <= 9)
        return char('0' + num);
    else if (num <= 36)
        return char('a' + num - 10);
    else {
        cout << "Conversion Failed" << endl;
        exit(EXIT_FAILURE);
    }
}

/*!
 * Convert a character to number greater than 0
 * Conversion failure return -1
 */
int to_digit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 10;
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10;
    } else
        return -1;
}

bool have_operator(const string &str) {
    switch (str[0]) {
        case '-':
        case '+':
            return true;
        default: {
            return false;
        }
    }
}

int main() {
    string filename = "/home/sparkai/work/DataStructure/test/InputInteger.txt";
    vector<int> num_list1, num_list2;
    vector<char> result_list;
    string str;
    int base = 10;
    char sign1 = '+', sign2 = '+', sign;
    ifstream ifs(filename, ios::in);

    if (!ifs.is_open()) {
        cout << "Cannot open file " << filename << endl;
        exit(-1);
    }

    getline(ifs, str);
    if (have_operator(str)) {
        sign1 = str[0];
        str[0] = '0';
    }
    num_list1 = string2vector(str, base);


    getline(ifs, str);
    if (have_operator(str)) {
        sign2 = str[0];
        str[0] = '0';
    }
    num_list2 = string2vector(str, base);
    sign = (sign1 == sign2 ? '+' : '-');
    result_list = operate_vector(num_list1, num_list2, base, sign);
    print_result(result_list);

    return 0;
}

vector<int> string2vector(const string &s, int base) {
    vector<int> v;
    char ch;
    int num = 0;
    istringstream iss(s);

    while (iss.get(ch)) {
        num = to_digit(ch);
        if (num == -1 || num > base) {
            cout << "Conversion failed: " << ch << " to number";
            exit(EXIT_FAILURE);
        }
        v.push_back(num);
    }
    return std::move(v);
}

int calculate(int n1, int n2, char sign) {
    switch (sign) {
        case '-':
            return n1 - n2;
        case '+':
            return n1 + n2;
        default: {
            cout << "Unsupported operator" << sign << endl;
            exit(EXIT_FAILURE);
        }
    }
}


vector<char> operate_vector(vector<int> &v1, vector<int> &v2, int base, char sign = '+') {
    vector<char> result_list;
    int b = 0;
    istringstream iss;
    while (true) {
        auto num1 = v1.empty() ? 0 : v1.back();
        auto num2 = v2.empty() ? 0 : v2.back();
        int sum = calculate(num1, num2, sign) + b;

        if (sum > base) {
            result_list.push_back(number_to_char(sum - base));
            b = 1;
        } else {
            if (sum < 0) {
                sum += base;
                b = -1;
            } else
                b = 0;
            result_list.push_back(number_to_char(sum));
        }
        if (!v1.empty()) v1.pop_back();
        if (!v2.empty()) v2.pop_back();
        if (v1.empty() && v2.empty()) break;
    }
    if (b == -1) result_list.push_back('-');
    return std::move(result_list);
}

