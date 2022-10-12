//
// Created by shiby on 22-10-8.
//
#include <memory>
#include <iostream>


void func(const int *ptr) {
    std::cout << "~shared_ptr\n";
    delete ptr;
}

int main() {
    const int *p = new int(10);

    std::shared_ptr<const int> ptr(p, func);
    std::cout << *ptr << std::endl;

    return 0;
}