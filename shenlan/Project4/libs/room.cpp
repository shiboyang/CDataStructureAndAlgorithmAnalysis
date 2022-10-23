//
// Created by shiby on 22-10-21.
//
#include <random>
#include "room.h"
#include "event.h"
#include "role.h"
#include "buff.h"


Campsite::Campsite() {
    this->enter_event = new RestoreHPEvent;
}

Campsite::~Campsite() {
    delete this->enter_event;
    delete this->enter_buff;
    delete this->encounter_event;
    std::cout << "~Campsite" << std::endl;
}

//营地只有进入事件
void Campsite::operator()(Person *user) {
    if (this->enter_event != nullptr) {
        (*this->enter_event)(*user);
    }
}

void Campsite::encounter(Person *user) {
    if (this->encounter_event != nullptr)
        (*this->encounter_event)(*user);
}


Room::Room() {
    if (random() % 10 == 0)
        this->enter_event = new RestoreHPEvent;
    this->enter_buff = new CureBuff(10, 2);
    this->encounter_event = new EncounterEvent(1, 3, 0.4);
}

Room::~Room() {
    delete this->enter_event;
    delete this->enter_buff;
    delete this->encounter_event;
    std::cout << "~Room" << std::endl;
}

void Room::operator()(Person *user) {
    if (this->enter_event != nullptr) { (*this->enter_event)(*user); };
    if (this->enter_buff != nullptr) {
        user->add_buff(*this->enter_buff);
        this->enter_buff = nullptr;
    }
}

void Room::encounter(Person *user) {
    if (this->encounter_event)
        (*this->encounter_event)(*user);
}
