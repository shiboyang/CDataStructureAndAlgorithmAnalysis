//
// Created by shiby on 22-10-21.
//
#include "event.h"
#include "role.h"
#include "utils.h"
#include "buff.h"

bool Event::have_completed() {
    return state == completed;
}

void CureEvent::operator()(Person *user) {
    print_event(this->event_message, user->state());
    if (hp > 0)
        user->cure(hp);
    else
        user->cure();
}

CureEvent::CureEvent(uint hp) : hp(hp) {
    event_message = "恢复探险者" + std::to_string(hp) + "生命";
}


void LossHPEvent::operator()(Person *user) {
    print_event(event_message, user->state());
    user->injure(harm);
}


EncounterEvent::EncounterEvent(int num_monster, double addition, bool random_add, bool create_monster) {
    auto _addition = addition;
    for (int i = 0; i < num_monster; ++i) {
        if (random_add) {
            _addition = (randint(2)) ? addition : addition * -1;
        }
        _addition += 1;
        Monster *monster;
        if (create_monster)
            monster = new Monster(_addition, "怪物" + std::to_string(i));
        else
            monster = new Boss(_addition, "怪物首领" + std::to_string(i));

        this->monster_list.push_back(monster);
    }
}


EncounterEvent::EncounterEvent(int start, int end, double addition, bool random_add, bool create_monster) {
    auto num_monster = randint(start, end);
    auto _addition = addition;
    for (int i = 0; i < num_monster; ++i) {
        if (random_add) {
            _addition = (randint(2)) ? addition : addition * -1;
        }
        _addition += 1;
        auto monster = new Monster(_addition, "怪物" + std::to_string(i));
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
        user->gan(*monster);
        print_attack_message(user, *monster);

        if ((*monster)->is_dead()) {
            ++exp;
            print_dead_message(*monster);
            ++monster;
        }

        for (auto m = monster; m < monster_list.end(); ++m) {
            (*m)->gan(user);
            print_attack_message(*m, user);
        }
    }
    if (!user->is_dead()) {
        state = completed;
        if (exp > 0) {
            user->add_exp(exp);
            print_add_experience_message(user, exp);
        }
    } else {
        print_dead_message(user);
    }
}

void EncounterEvent::add_monster(Monster *monster) {
    monster_list.push_back(monster);
}


void ProportionLossHPEvent::operator()(Person *user) {
    auto hp = user->get_hp();
    user->injure(uint(hp * proportion));
    print_event(event_message, user->state());
}

void CleanBadBuffEvent::operator()(Person *user) {
    auto buff_ptr = user->buff_list.begin();
    while (buff_ptr != user->buff_list.end()) {
        if (!(*buff_ptr)->is_good()) {
            buff_ptr = user->buff_list.erase(buff_ptr);
        } else
            ++buff_ptr;
    }
    print_event(event_message);
}


void AddBuffEvent::operator()(Person *user) {
    user->add_buff(buff);
    buff = nullptr;
}

void SnapshotEvent::operator()(Person *user) {
    hp = user->get_hp();
}

void RecoverEvent::operator()(Person *user) {
    if (snapshot->hp > user->get_hp())
        user->cure(snapshot->hp - user->get_hp());
    else
        user->injure(user->get_hp() - snapshot->hp);
}

void ExperienceEvent::operator()(Person *user) {
    user->add_exp(exp);
}

void WearEquipment::operator()(Person *user) {
    user->wear(weapon);
    print_wear_weapon_message(user, weapon);
}
