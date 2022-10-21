//
// Created by shiby on 22-10-20.
//

//#include "role.h"



class A {


public:
    int pub_num = 1;

protected:
    int prot_num = 2;
};


class B : public A {
public:
    B(): {
        prot_num = 100;
    }
};

int main() {

    B b;
    return 0;
}