//
// Created by shiby on 22-10-20.
//

#include <sstream>
#include "role.h"
#include "buff.h"
#include "utils.h"
#include "weapon.h"

bool LiveObject::is_dead() const {
    return this->hp <= 0;
}

std::string LiveObject::state() const {
    std::string s = "(" + std::to_string(hp) + "/" + std::to_string(max_hp) + ")";
    return std::move(s);
}

uint LiveObject::get_atk() const {
    return atk;
}

void LiveObject::gan(LiveObject *other) const {
    if (weapon != nullptr) {
        weapon->attack(other);
    } else {
        other->injure(this->atk);
    }
}

void LiveObject::injure(uint harm) {
    this->hp = (this->hp > harm) ? this->hp - harm : 0;
}

uint LiveObject::get_hp() const {
    return hp;
}

void LiveObject::wear(Weapon *equipment) {

    weapon = equipment;
    equipment->owner = this;
}


Weapon *LiveObject::takeoff(Weapon *equipment) {
    auto ret = weapon;
    weapon = nullptr;
    return ret;
}

void LiveObject::add_atk(uint attack) {
    if (attack > 0) {
        this->atk += attack;
    }
}

LiveObject::~LiveObject() {
    delete weapon;
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

void Person::add_buff(Buff *buff) {
    buff_list.push_back(buff);
}

Person::~Person() {
    for (auto x: buff_list) {
        delete x;
    }
}


void Person::buff() {
    auto buff_prt = buff_list.begin();
    while (buff_prt != buff_list.end()) {
        if ((*buff_prt)->expired())
            buff_prt = buff_list.erase(buff_prt);
        else {
            (**buff_prt)(this);
            ++buff_prt;
        }
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


