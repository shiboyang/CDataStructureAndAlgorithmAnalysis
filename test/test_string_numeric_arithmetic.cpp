//
// Created by shiby on 22-9-25.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>


using namespace std;


vector<char> string2vector(const string &s);

void print_vector(vector<char> &v);

vector<char> add_vector(vector<char> &v1, vector<char> &v2);

void print_result(vector<int> &result);


bool is_digit(char ch)
{
    const
}

int main() {
    string filename = "/home/sparkai/work/DataStructure/test/InputInteger.txt";
    vector<char> num_list1, num_list2, result_list;
    string str;
    ifstream ifs(filename, ios::in);

    if (!ifs.is_open()) {
        cout << "Cannot open file " << filename << endl;
        exit(-1);
    }

    getline(ifs, str);
    num_list1 = string2vector(str);

    getline(ifs, str);
    num_list2 = string2vector(str);

    print_vector(num_list1);
    print_vector(num_list2);

//    result_list = add_vector(num_list1, num_list2);
//    print_result(result_list);


    return 0;
}

vector<char> string2vector(const string &s, int base) {
    vector<char> v;
    char ch;
    istringstream iss(s);
    for(auto x: s){

    }

    while (iss.get(ch)) {
        if (!isdigit(ch)) {
            cout << "Invalid " << ch << "to convert to integer";
            exit(EXIT_FAILURE);
        }
        v.push_back(ch);
    }
    return std::move(v);
}

void print_vector(vector<char> &v) {
    for (auto i: v) {
        cout << i << endl;
    }
}

vector<char> add_vector(vector<char> &v1, vector<char> &v2, int base) {
    vector<char> result_list;
    int b = 0;
    char ch;
    istringstream iss;
    while (true) {
        ch = v1.empty() ? '0' : v1.back();
        iss.str(ch);
        auto num1 = v1.empty() ? '0' : v1.back();
        auto num2 = v2.empty() ? '0' : v2.back();
        int sum = num1 + num2 + b;
        if (sum > 1000) {
            result_list.push_back(sum - 1000);
            b = 1;
        } else {
            result_list.push_back(sum);
            b = 0;
        }
        if (!v1.empty()) v1.pop_back();
        if (!v2.empty()) v2.pop_back();
        if (v1.empty() && v2.empty()) break;
    }
    return std::move(result_list);
}

void print_result(vector<int> &result) {
    for (size_t i = result.size(); i > 0; --i) {
        cout.fill('0');
        cout.width(3);
        cout << result[i - 1] << ",";
    }
}