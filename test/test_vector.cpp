//
// Created by shiby on 22-9-23.
//

#include <iostream>
#include <vector>

int main() {

    std::vector<int> t1;
    t1.push_back(1);
    t1.push_back(2);
    t1.push_back(3);

    for (auto x: t1) {
        std::cout << x << std::endl;
    }
    std::cout << "=============\n";

    t1.pop_back();
    for (auto x: t1) {
        std::cout << x << std::endl;
    }


    return 0;
}