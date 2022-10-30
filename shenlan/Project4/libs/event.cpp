//
// Created by shiby on 22-10-21.
//
#include <sstream>
#include "event.h"
#include "role.h"
#include "utils.h"
#include "buff.h"

bool Event::have_completed() {
    return state == completed;
}

std::string Event::print() {
    return "";
}


void CureEvent::operator()(Person *user) {
    if (hp > 0)
        user->cure(hp);
    else
        user->cure();
    print_msg(this->print());
}

std::string CureEvent::print() {
    std::ostringstream oss;
    oss << "恢复探险者";
    if (hp > 0)
        oss << hp << "生命";
    else
        oss << "全部生命";
    return std::move(oss.str());
}


BattleEvent::~BattleEvent() {
    for (auto x: this->monster_list) delete x;
}

void BattleEvent::operator()(Person *user) {
    print_msg(this->print());
    auto monster = monster_list.begin();
    while (!user->is_dead() && monster < monster_list.end()) {
        user->fight(*monster);
        if ((*monster)->is_dead()) {
            print_dead_message(*monster);
            ++monster;
        }

        for (auto m = monster; m < monster_list.end(); ++m) {
            (*m)->fight(user);
            if (user->is_dead())
                break;
        }
    }
    if (!user->is_dead()) {
        state = completed;
    }
}

void BattleEvent::add_monster(Monster *monster) {
    monster_list.push_back(monster);
}

std::string BattleEvent::print() {
    std::ostringstream oss;
    oss << "遇战: ";
    for (auto m: monster_list) {
        oss << m->name << m->state() << " ";
    }
    oss << "\n战斗开始";
    return std::move(oss.str());
}


void ProportionLossHPEvent::operator()(Person *user) {
    auto hp = user->get_hp();
    user->injure(uint(hp * proportion));
    print_msg(this->print());
}

std::string ProportionLossHPEvent::print() {
    std::ostringstream oss;
    oss << "探险者损失当前百分之" << int(proportion * 100) << "的生命";
    return std::move(oss.str());
}


void CleanBadBuffEvent::operator()(Person *user) {
    auto buff_ptr = user->buff_list.begin();
    while (buff_ptr != user->buff_list.end()) {
        if (!(*buff_ptr)->is_good()) {
            buff_ptr = user->buff_list.erase(buff_ptr);
        } else
            ++buff_ptr;
    }
    print_msg(this->print());
}

std::string CleanBadBuffEvent::print() {
    std::ostringstream oss;
    oss << "清除所有负面效果";
    return std::move(oss.str());
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
    print_msg(this->print() + " " + user->state());
}

std::string RecoverEvent::print() {
    std::ostringstream oss;
    oss << "恢复生命值为进入房间的状态";
    return std::move(oss.str());
}


void ExperienceEvent::operator()(Person *user) {
    user->add_exp(exp);
    print_add_experience_message(user, exp);
    user->upgrade();

}

void WearEquipment::operator()(Person *user) {
    user->wear(weapon);
    print_wear_weapon_message(user, weapon);
}
