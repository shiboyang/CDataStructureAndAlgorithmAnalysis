//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_UTILS_H
#define PROJECT4_UTILS_H

#include <iostream>

class Person;

class Monster;

class LiveObject;

class Weapon;

class Event;

const uint DELAY_SECONDS = 0;


int randint(int start, int end);

int randint(int value);

void print_event(const std::string &event_message, const std::string &user_state);

void print_event(const std::string &event_message);

void print_event(Event *event);

void print_msg(const std::string &str);

void delay_print(const std::string &msg, uint s);


void print_attack_message(const LiveObject *attack, const LiveObject *monster, uint harm, int step);

void print_dead_message(const LiveObject *obj);

void print_upgrade_message(const Person *user);

void print_add_experience_message(const Person *user, uint exp);

void print_weapon_message(const Weapon *weapon);

void print_weapon_property_message(const std::string &property_message, const LiveObject *user);


void print_wear_weapon_message(LiveObject *user, const Weapon *weapon);

#endif //PROJECT4_UTILS_H
