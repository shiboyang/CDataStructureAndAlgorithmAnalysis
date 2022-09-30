//
// Created by shiby on 22-9-23.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Invalid arguments.";
        exit(-1);
    }

    string filename = argv[1];
    cout << argv[2] << endl;
    unsigned int base = *(argv[2]);

    ifstream iss(filename, ios::in);


    if (!iss.is_open()) {
        std::cout << "Can not open file " << filename << std::endl;
        std::exit(-1);
    }

    string s1, s2;
    getline(iss, s1);
    getline(iss, s2);

    vector<char> v1, v2, result;

    // 判断s2开头是+ -
    if (s2[0] != '-' && s2[0] != '+') {
        cout << "Invalid input string " << s2 << endl;
        exit(-1);
    }

    for (auto x: s1) {
        v1.push_back(x);
    }

    for (auto x: s2) {
        v2.push_back(x);
    }

    cout << base << endl;


    return 0;
}