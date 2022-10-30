//
// Created by shiby on 22-10-21.
//
#include "room.h"
#include "event.h"
#include "role.h"
#include "buff.h"
#include "utils.h"
#include "weapon.h"


void BaseRoom::operator()(Person *user) {
    print_msg("[" + name + "]");
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


Campsite::Campsite(const std::string &name) : BaseRoom(name) {
    event_list.push_back(new CureEvent);
}

/*!
 * enter_event 10%概率恢复10点生命
 * buff_event 恢复5生命 持续2房间
 * battle_event 随机生成1-3个怪物属性值为基本属性的+-40%
 */
Room::Room(const std::string &name) : BaseRoom(name) {
    if (randint(10) == 0)
        event_list.push_back(new CureEvent(10));
    event_list.push_back(new AddBuffEvent(new CureBuff(5, 2)));
    auto num = randint(1, 3);
    auto battle_event = new BattleEvent;
    for (int i = 0; i < num; ++i) {
        auto addition = (randint(0, 1) % 2) ? 1.4 : 0.6;
        auto monster = new Monster(addition, "怪物" + std::to_string(i));
        battle_event->add_monster(monster);
    }
    event_list.push_back(battle_event);
    event_list.push_back(new ExperienceEvent(num));
}

/*!
 * enter_event 探险者损失10%当前生命
 * buff_event 损失2点生命 持续5个房间
 * battle_event 1个基本属性值2倍的怪物
 */
TrapRoom::TrapRoom(const std::string &name) : BaseRoom(name) {
    event_list.push_back(new ProportionLossHPEvent(0.1));
    auto event = new AddBuffEvent(new LossHPBuff(5));
    event_list.push_back(event);
    auto battle_event = new BattleEvent;
    auto monster = new Monster(2.0, "怪物");
    battle_event->add_monster(monster);
    event_list.push_back(battle_event);
    event_list.push_back(new ExperienceEvent(1));
}

/*!
 * enter_event 恢复20点生命值 清除所有负面效果
 * battle_event 生成一个怪物首领
 */
BoosRoom::BoosRoom(const std::string &name) : BaseRoom(name) {
    event_list.push_back(new CureEvent(20));
    event_list.push_back(new CleanBadBuffEvent);
    auto battle_event = new BattleEvent;
    auto boss = new Boss("怪物首领");
    battle_event->add_monster(boss);
    event_list.push_back(battle_event);
    event_list.push_back(new ExperienceEvent(5));
}

/*!
 * enter_event 记录冒险者当前的生命值
 * battle_event 生成一个属性值为探索者基本属性0.4倍的怪物 并装备一把随机武器
 * event 退出房间探险者得到武器 并恢复进入房间时的生命值
 */
WeaponRoom::WeaponRoom(const std::string &name) : BaseRoom(name) {
    auto snapshot_event = new SnapshotEvent;
    event_list.push_back(snapshot_event);

    auto encounter_event = new BattleEvent;
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
