//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_EVENT_H
#define PROJECT4_EVENT_H

#include <vector>
#include <memory>


class Person;

class Monster;

class Event {
public:
    virtual void operator()(Person &) = 0;

    virtual ~Event() = default;
};


class RestoreHPEvent : public Event {
public:
    void operator()(Person &) override;
};


//class RandomGenerateMonster : public Event {
//public:
//    RandomGenerateMonster();
//
//    ~RandomGenerateMonster();
//
//    void operator()(Person &) override;
//
//protected:
//    std::vector<Monster> monster_list;
//};


class EncounterEvent : public Event {
public:
    explicit EncounterEvent(int num_monster, double addition = 0, bool random_add = true);

    EncounterEvent(int start, int end, double addition = 1.0, bool random_add = true);

    ~EncounterEvent() override;

    void operator()(Person &) override;

protected:
    std::vector<Monster *> monster_list;
};


#endif //PROJECT4_EVENT_H
