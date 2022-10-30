//
// Created by shiby on 22-10-21.
//
#include <sstream>
#include <random>
#include <unistd.h>
#include "utils.h"
#include "role.h"
#include "weapon.h"
#include "event.h"


int randint(int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(start, end);
    auto num = distrib(gen);
    return num;
}

int randint(int value) {
    return randint(1, value);
}


void delay_print(const std::ostringstream &oss, uint s = DELAY_SECONDS) {
    std::cout << oss.str() << std::endl;
    sleep(s);
}

void delay_print(const std::string &msg, uint s = DELAY_SECONDS) {
    std::cout << msg << std::endl;
    sleep(s);
}

void print_msg(const std::string &msg) {
    delay_print(msg);
}

void print_event(const std::string &event_message, const std::string &user_state) {
    std::ostringstream oss;
    oss << "触发事件, " << event_message << ", 当前生命" << user_state;
    delay_print(oss);
}

void print_event(const std::string &event_message) {
    std::ostringstream oss;
    oss << "触发事件, " << event_message;
    delay_print(oss);
}

void print_event(Event *event) {
    std::cout << event->print() << std::endl;
    sleep(DELAY_SECONDS);
}


void print_attack_message(const LiveObject *attacker, const LiveObject *obj, uint harm, int step) {
    std::ostringstream oss;
    oss << "回合" << step << ": " << attacker->name << "攻击" << obj->name << ", 造成" << harm << "伤害, " << obj->name
        << obj->state();
    delay_print(oss);
}

void print_dead_message(const LiveObject *obj) {
    std::ostringstream oss;
    oss << obj->name << "死亡";
    delay_print(oss);
}

void print_upgrade_message(const Person *user) {
    std::ostringstream oss;
    oss << user->name << "升级了(" << user->get_exp() << "/" << user->get_max_exp() << ")";
    delay_print(oss);
}

void print_add_experience_message(const Person *user, uint exp) {
    std::ostringstream oss;
    oss << "获得" << exp << "经验, 当前经验 (" << user->get_exp() << "/" << user->get_max_exp() << ")";
    delay_print(oss);
}


void print_weapon_message(const Weapon *weapon) {
    std::ostringstream oss;
    oss << "武器耐久度为:" << weapon->durability;
    delay_print(oss);
}

void print_weapon_property_message(const std::string &property_message, const LiveObject *user) {
    std::ostringstream oss;
    oss << "触发" << property_message;
    delay_print(oss);
}

void print_wear_weapon_message(LiveObject *user, const Weapon *weapon) {
    std::ostringstream oss;
    oss << user->name << "佩戴" << *weapon;
    delay_print(oss);
}
