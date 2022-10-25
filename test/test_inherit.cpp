//
// Created by shiby on 22-10-24.
//

#include <iostream>

class A {
public:
    A() = default;

    A(int num) : num(num) {}

    void print_num() {
        std::cout << num << std::endl;
    }

protected:
    int num = 100;
};


class B : public A {
public:
    B() {
        this->num = 999;
    }

};


class Base {
public:
    virtual void fun() {
        std::cout << "Base::fun is called. " << std::endl;
    }
};


class Derive : public Base {
public:
    void fun() {
        std::cout << "Derive::fun is called. " << std::endl;
    }
};


class Room {
public:
    Room(std::string &name) : name(name) {}

    void print_name() {
        std::cout << name << std::endl;
    }

protected:
    std::string name = "";
};


Room *modify_name() {
    std::string name = "new room";
    auto room = new Room(name);
    name  = "2 room";
    return room;
}


int main() {
    Room *room_ptr = modify_name();
    room_ptr->print_name();
}