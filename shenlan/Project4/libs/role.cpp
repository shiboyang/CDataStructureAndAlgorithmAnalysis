//
// Created by shiby on 22-10-20.
//

#include "role.h"

void Person::cure(unsigned int hp) {
    if (hp > this->max_hp)
        this->hp = this->max_hp;
    else
        this->hp += hp;
}

void Person::cure() {
    this->hp = this->max_hp;
}

void Person::cure(double percent) {
    auto cure_hp = u_int(this->max_hp * percent);
    this->cure(cure_hp);
}

void Person::add_buff(Buff &buff) {
    this->buff_list.push_back(&buff);
}

Person::~Person() {
    for (auto x: buff_list) {
        delete x;
    }
    buff_list.clear();
}

