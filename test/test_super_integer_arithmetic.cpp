//
// Created by shiby on 22-9-25.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#define int_size  sizeof(int)

void string2vector(vector<int>& v, const string& s);
void print_vector(vector<int>& v);

int main()
{
	string filename = "/home/shiby/code/DataStructure/test/InputInteger.txt";
	vector<int> num1, num2;
	istringstream iss2;

	string s1;

	ifstream ifs(filename, ios::in);

	if (!ifs.is_open()) {
		cout << "Cannot open file " << filename << endl;
		exit(-1);
	}

//	getline(ifs, s1);
//	string2vector(num1, s1);
//
//	getline(ifs, s1);
//	string2vector(num2, s1);
//
//	print_vector(num1);
//	print_vector(num2);

	num1.push_back(1);
	num1.push_back(2);
	num1.pop_back();

	return 0;
}

void string2vector(vector<int>& v, const string& s)
{
	string str(int_size, '\0');
	istringstream iss(s);
	istringstream iss2;
	int tmp_num;

	while (iss.read(&str[0], int_size-1)) {
		iss2.str(str);
		iss2 >> tmp_num;
		v.push_back(tmp_num);
	}
}

void print_vector(vector<int>& v)
{
	for (int i : v) {
		cout << i << endl;
	}
}

void add_vector(vector<int>& v1, vector<int>& v2, vector<int>& result)
{

}