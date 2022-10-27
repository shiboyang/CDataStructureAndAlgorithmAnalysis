//
// Created by shiby on 22-9-27.
//
#include <iostream>
#include <string>
#include <algorithm>


class A {
public:
    A(int num) {
        this->m = num;
    };

    void print_num() const {
        std::cout << m << std::endl;
    }


    int m;
};

int main() {
    A a(100);
    A *p = &a;
    A &af = a;

    auto b = new decltype()(200);
    b->m = 999;

    b->print_num();
    return 0;
}