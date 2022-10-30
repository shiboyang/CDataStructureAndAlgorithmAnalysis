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

uint LiveObject::gan(LiveObject *other) {
    uint harm = 0;
    std::ostringstream oss;
    if (weapon != nullptr) {
        harm = weapon->attack(other);
    } else {
        harm = this->atk;
        other->injure(harm);
    }
    return harm;
}

void LiveObject::injure(uint harm) {
    this->hp = (this->hp > harm) ? this->hp - harm : 0;
}

uint LiveObject::get_hp() const {
    return hp;
}

void LiveObject::wear(Weapon *equipment) {
    this->takeoff();
    weapon = equipment;
    equipment->owner = this;
}


void LiveObject::takeoff() {
    std::ostringstream oss;
    if (weapon != nullptr) {
        oss << name << "脱下装备：" << weapon->name;
        print_msg(oss.str());
    }
    delete weapon;
    weapon = nullptr;
}

void LiveObject::add_atk(uint attack) {
    this->atk += attack;
}

LiveObject::~LiveObject() {
    delete weapon;
}

void LiveObject::fight(LiveObject *other) {
    std::ostringstream oss;
    oss << this->name;
    auto harm = this->gan(other);
    if (this->weapon != nullptr)
        oss << "使用" << weapon->name;
    oss << "攻击" << other->name << ", 造成" << harm << "伤害, " << other->name << other->state();
    print_msg(oss.str());
    if (weapon != nullptr && weapon->durability == 0) {
        oss.clear();
        oss.str("");
        oss << this->name << "的" << weapon->name << "(" << weapon->durability << "/" << weapon->max_durability
            << ")" << "被销毁";
        this->takeoff();
        print_msg(oss.str());
    }
}


void LiveObject::cure(uint blood) {
    this->hp = (this->hp + blood > this->max_hp) ? max_hp : this->hp + blood;
}

void LiveObject::cure() {
    this->hp = this->max_hp;
}

void LiveObject::cure(double percent) {
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
    auto buff_ptr = buff_list.begin();

    while (buff_ptr != buff_list.end()) {
        (**buff_ptr)(this);
        ++buff_ptr;
    }
    buff_ptr = buff_list.begin();
    while (buff_ptr != buff_list.end()) {
        if ((*buff_ptr)->expired()) {
            std::ostringstream oss;
            oss << (*buff_ptr)->message << "移除";
            delete *buff_ptr;
            buff_ptr = buff_list.erase(buff_ptr);
            print_msg(oss.str());
        }
        ++buff_ptr;
    }
}


void Person::add_exp(uint ex) {
    this->exp += ex;

}

uint Person::get_exp() const {
    return exp;
}

void Person::upgrade() {
    if (this->exp > max_exp) {
        this->exp -= max_exp;
        this->hp = this->max_exp;
        print_upgrade_message(this);
    }
}

uint Person::get_max_exp() const {
    return max_exp;
}


void Boss::fight(LiveObject *other) {
    if (hp <= 10 && !have_cure) {
        this->cure(uint(20));
        this->have_cure = true;
        print_msg(name + "恢复20血量, " + state());
    } else {
        auto atk = randint(1, 5);
        this->atk += atk;
        LiveObject::fight(other);
        this->atk -= atk;
    }
}
