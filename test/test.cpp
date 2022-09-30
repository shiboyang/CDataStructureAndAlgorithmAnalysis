//
// Created by shiby on 22-9-27.
//
#include <iostream>
#include <sstream>

using namespace std;


int main() {

    istringstream iss(";123;123");
    string s1(4, '\0');
    iss.read(&s1[0], 4);
    cout << s1 << endl;
    int i;
    iss >> i;
    cout << i << " " << iss.fail() << endl;

    iss >> i;
    cout << i << " " << iss.fail() << endl;


    return 0;
}