//
// Created by shiby on 22-10-20.
//

#include <sstream>
#include "role.h"
#include "buff.h"
#include "utils.h"

bool LiveObject::is_dead() const {
    return this->hp <= 0;
}

std::string LiveObject::state() const {
    std::ostringstream oss;
    oss << "(" << this->hp << "/" << this->max_hp << ")";
    return std::move(oss.str());
}

uint LiveObject::get_atk() const {
    return atk;
}

void LiveObject::attack(LiveObject *obj) const {
    obj->injure(this->atk);
}

void LiveObject::injure(uint harm) {
    this->hp = (this->hp > harm) ? this->hp - harm : 0;
}


void Person::cure(uint blood) {
    this->hp = (this->hp + blood > this->max_hp) ? max_hp : this->hp + blood;
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


void Person::buff() {
    for (auto x: buff_list) {
        (*x)(this);
    }
}

void Person::add_exp(uint ex) {
    this->exp += ex;
    if (this->exp > max_exp) {
        print_upgrade_message(this);
        this->exp -= max_exp;
        this->hp = this->max_exp;
    }
}

std::string Person::get_exp() const {
    std::ostringstream oss;
    oss << "(" << exp << "/" << max_exp << ")";
    return std::move(oss.str());
}


