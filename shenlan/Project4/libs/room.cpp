//
// Created by shiby on 22-10-21.
//
#include <random>
#include "room.h"
#include "event.h"
#include "role.h"
#include "buff.h"
#include "utils.h"
#include "weapon.h"


void BaseRoom::operator()(Person *user) {
    std::cout << "进入" << name << std::endl;
    user->buff();
    auto begin = event_list.begin();
    while (begin != event_list.end()) {
        (**begin)(user);
        if (user->is_dead()) {
            print_dead_message(user);
            break;
        }
        ++begin;
    }
}

BaseRoom::~BaseRoom() {
    for (auto &item: event_list) {
        delete item;
    }
}


//void BaseRoom::settle(Person *user) {
//    if (!user->is_dead() && encounter_event->have_completed()) {
//
//    }
//}

std::string BaseRoom::get_name() {
    return name;
}


Campsite::Campsite(const std::string &name) : BaseRoom(name) {
    event_list.push_back(new CureEvent);
}

Room::Room(const std::string &name) : BaseRoom(name) {
    if (random() % 10 == 0)
        event_list.push_back(new CureEvent(10));
    auto event = new AddBuffEvent(new CureBuff(5, 2));
    event_list.push_back(event);
    event_list.push_back(new EncounterEvent(1, 3, 0.4));
}


TrapRoom::TrapRoom(const std::string &name) : BaseRoom(name) {
    event_list.push_back(new ProportionLossHPEvent(0.1));
    auto event = new AddBuffEvent(new LossHPBuff(5));
    event_list.push_back(event);
    event_list.push_back(new EncounterEvent(1, 1.0, false));
}

BoosRoom::BoosRoom(const std::string &name) : BaseRoom(name) {
    event_list.push_back(new CureEvent(20));
    event_list.push_back(new CleanBadBuffEvent);
    event_list.push_back(new EncounterEvent(1, 0.0, false, false));
}

EquipmentRoom::EquipmentRoom(const std::string &name) : BaseRoom(name) {
    auto snapshot_event = new SnapshotEvent;
    event_list.push_back(snapshot_event);

    auto encounter_event = new EncounterEvent;
    auto monster = new Monster(100 * 0.4, 10 * 0.4, 100 * 0.4, "领主");
    auto i = randint(1, 3);
    Weapon *weapon, *weapon1;
    switch (i) {
        case 1: {
            weapon = new Weapon;
            weapon1 = new Weapon;
            break;
        }
        case 2: {
            weapon = new Weapon2;
            weapon1 = new Weapon2;
            break;
        }
        default: {
            weapon = new Weapon3;
            weapon1 = new Weapon3;
        }
    }
    monster->wear(weapon);
    encounter_event->add_monster(monster);
    event_list.push_back(encounter_event);
    event_list.push_back(new ExperienceEvent(2));
    event_list.push_back(new RecoverEvent(snapshot_event));
    event_list.push_back(new WearEquipment(weapon1));
}
