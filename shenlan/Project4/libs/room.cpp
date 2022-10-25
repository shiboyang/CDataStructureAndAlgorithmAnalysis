//
// Created by shiby on 22-10-21.
//
#include <random>
#include "room.h"
#include "event.h"
#include "role.h"
#include "buff.h"


void BaseRoom::operator()(Person *user) {
    std::cout << "进入" << name << std::endl;
    user->buff();
    if (enter_event != nullptr) (*enter_event)(user);
    if (enter_buff != nullptr) {
        user->add_buff(*this->enter_buff);
        enter_buff = nullptr;
    }
}

BaseRoom::~BaseRoom() {
    delete this->enter_event;
    delete this->enter_buff;
    delete this->encounter_event;
}

void BaseRoom::encounter(Person *user) {
    if (this->encounter_event) (*this->encounter_event)(user);
}

void BaseRoom::settle(Person * user) {
    if (!user->is_dead() && encounter_event->have_completed()){

    }
}


Campsite::Campsite(const std::string &name) : BaseRoom(name) {
    this->enter_event = new RestoreHPEvent;
}

Room::Room(const std::string &name) : BaseRoom(name) {
    if (random() % 10 == 0)
        this->enter_event = new RestoreHPEvent;
    this->enter_buff = new CureBuff(5, 2);
    this->encounter_event = new EncounterEvent(1, 3, 0.4);
}




