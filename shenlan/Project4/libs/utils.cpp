//
// Created by shiby on 22-10-21.
//

#include <random>
#include <sstream>
#include <unistd.h>
#include "utils.h"
#include "role.h"
#include "weapon.h"


int randint(int start, int end) {
    auto num = int(random() % end);
    num = (num < start) ? end - num : num;
    return num;
}

int randint(int value) {
    return int(random() % value);
}


void delay_print(uint s, std::ostringstream &oss) {
    std::cout << oss.str() << std::endl;
    usleep(1000 * s);
}

void print_event(const std::string &event_message, const std::string &user_state) {
    std::cout << "触发事件, " << event_message << ", 当前生命" << user_state << std::endl;
}

void print_event(const std::string &event_message) {
    std::cout << "触发事件, " << event_message << std::endl;
}

void print_attack_message(const LiveObject *attacker, const LiveObject *obj) {
    std::cout << attacker->name << "攻击" << obj->name << ", 造成" << attacker->get_atk() << "伤害, " << obj->name
              << obj->state() << std::endl;
}

void print_dead_message(const LiveObject *obj) {
    std::cout << obj->name << "死亡" << std::endl;
}

void print_upgrade_message(const Person *user) {
    std::cout << user->name << "升级了" << user->get_exp() << std::endl;
}

void print_add_experience_message(const Person *user, uint exp) {
    std::cout << "获得" << exp << "经验, 当前经验" << user->get_exp() << std::endl;
}


void print_weapon_message(const Weapon *weapon) {
    std::ostringstream oss;
    oss << "武器耐久度为:" << weapon->durability;
    delay_print(1, oss);
}

void print_weapon_property_message(const std::string &property_message, const LiveObject *user) {
    std::ostringstream oss(property_message);
    oss << "触发武器属性 攻击力:" << user->get_atk();
    delay_print(1, oss);
}

void print_wear_weapon_message(LiveObject *user, const Weapon *weapon) {
    std::ostringstream oss;
    oss << user->name << "获得" << *weapon;
    delay_print(1, oss);
}



