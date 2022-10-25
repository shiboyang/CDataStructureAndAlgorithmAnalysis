//
// Created by shiby on 22-10-21.
//
#include <sstream>
#include "event.h"
#include "role.h"
#include "utils.h"

bool Event::have_completed() {
    return state == completed;
}

void RestoreHPEvent::operator()(Person *user) {
    print_event(this->event_message, user->state());
    user->cure();
}


EncounterEvent::EncounterEvent(int num_monster, double addition, bool random_add) {
    for (int i = 0; i < num_monster; ++i) {
        if (random_add) {
            addition = (randint(2)) ? (addition + 1) : (1 - addition);
        }
        std::ostringstream oss;
        oss << "怪物" << i;
        auto monster = new Monster(addition, oss.str());
        this->monster_list.push_back(monster);
    }
}


EncounterEvent::EncounterEvent(int start, int end, double addition, bool random_add) {
    auto num_monster = randint(start, end);
    auto _addition = addition;
    for (int i = 0; i < num_monster; ++i) {
        std::ostringstream oss;
        if (random_add) {
            _addition = (randint(2)) ? (addition + 1) : (1 - addition);
        }
        oss << "怪物" << i;
        auto monster = new Monster(_addition, oss.str());
        this->monster_list.push_back(monster);
    }
}


EncounterEvent::~EncounterEvent() {
    for (auto x: this->monster_list) delete x;
}

void EncounterEvent::operator()(Person *user) {
    std::cout << "战斗开始" << std::endl;
    uint exp = 0;
    auto monster = monster_list.begin();
    while (!user->is_dead() && monster < monster_list.end()) {
        user->attack(*monster);
        print_attack_message(user, *monster);

        if ((*monster)->is_dead()) {
            ++exp;
            print_dead_message(*monster);
            ++monster;
        }

        for (auto m = monster; m < monster_list.end(); ++m) {
            (*m)->attack(user);
            print_attack_message(*m, user);
        }
    }
    if (!user->is_dead()) {
        state = completed;
        if (exp > 0) {
            user->add_exp(exp);
            print_add_experience_message(user, exp);
        }
    }
}


