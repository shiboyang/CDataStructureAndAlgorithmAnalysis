//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_EVENT_H
#define PROJECT4_EVENT_H

#include <vector>
#include <memory>
#include <string>


class Buff;

class Person;

class Monster;

class Weapon;

enum EventState {
    pending,
    completed
};

class Event {
public:
    virtual void operator()(Person *) = 0;

    virtual ~Event() = default;

    bool have_completed();

    virtual std::string print();

protected:
    EventState state = pending;
};

class CureEvent : public Event {
public:
    CureEvent() = default;

    explicit CureEvent(uint hp) : hp(hp) {};

    void operator()(Person *) override;

    std::string print() override;

protected:
    const uint hp = 0;
};


class ProportionLossHPEvent : public Event {
public:
    explicit ProportionLossHPEvent(double proportion) : proportion(proportion) {};

    void operator()(Person *) override;

    std::string print() override;


protected:
    const double proportion;
};

class BattleEvent : public Event {
public:
    BattleEvent() = default;

    ~BattleEvent() override;

    void operator()(Person *) override;

    void add_monster(Monster *);

    std::string print() override;

protected:
    std::vector<Monster *> monster_list;
};


class CleanBadBuffEvent : public Event {
public:
    void operator()(Person *) override;

    std::string print() override;

protected:
};


class AddBuffEvent : public Event {
public:
    explicit AddBuffEvent(Buff *buff) : buff(buff) {};

    void operator()(Person *) override;

protected:
    Buff *buff;
};

class SnapshotEvent : public Event {
public:
    uint hp = 0;

    void operator()(Person *) override;
};

class RecoverEvent : public Event {
public:
    explicit RecoverEvent(SnapshotEvent *snapshot) : snapshot(snapshot) {};

    void operator()(Person *) override;

    std::string print() override;

protected:
    SnapshotEvent *snapshot;
};

class ExperienceEvent : public Event {
public:
    explicit ExperienceEvent(uint exp) : exp(exp) {};

    void operator()(Person *) override;

private:
    uint exp;
};

class WearEquipment : public Event {
public:
    explicit WearEquipment(Weapon *equipment) : weapon(equipment) {};

    void operator()(Person *) override;

protected:
    Weapon *weapon;
};


#endif //PROJECT4_EVENT_H
