//
// Created by shiby on 22-10-21.
//

#include "event.h"
#include "role.h"
#include "utils.h"

void RestoreHPEvent::operator()(Person &user) {
    user.cure();
}


EncounterEvent::EncounterEvent(int num_monster, double addition, bool random_add) {

    for (int i = 0; i < num_monster; ++i) {
        if (random_add) {
            addition = (randint(2)) ? (addition + 1) : (1 - addition);
        }
        auto monster = new Monster(addition);
        this->monster_list.push_back(monster);
    }
}


EncounterEvent::EncounterEvent(int start, int end, double addition, bool random_add) {
    auto num_monster = randint(start, end);
    for (int i = 0; i < num_monster; ++i) {
        if (random_add) {
            addition = (randint(2)) ? (addition + 1) : (1 - addition);
        }
        auto monster = new Monster(addition);
        this->monster_list.push_back(monster);
    }
}


EncounterEvent::~EncounterEvent() {
    for (auto x: this->monster_list) {
        delete x;
    }
}

void EncounterEvent::operator()(Person &user) {

}
