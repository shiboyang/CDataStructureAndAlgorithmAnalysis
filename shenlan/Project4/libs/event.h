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

protected:
    EventState state = pending;
};

class CureEvent : public Event {
public:
    CureEvent() = default;

    explicit CureEvent(uint hp);

    void operator()(Person *) override;

protected:
    std::string event_message = "恢复探险者全部生命";
    const uint hp = 0;
};


class LossHPEvent : public Event {
public:
    explicit LossHPEvent(uint hp) : harm(hp) {};

    void operator()(Person *) override;

protected:
    const uint harm;
    const std::string event_message = "探险者损失" + std::to_string(harm) + "的生命";
};

class ProportionLossHPEvent : public Event {
public:
    explicit ProportionLossHPEvent(double proportion) : proportion(proportion) {};

    void operator()(Person *) override;

protected:
    const double proportion;
    const std::string event_message = "探险者损失当前百分之" + std::to_string(proportion) + "的生命";
};

class EncounterEvent : public Event {
public:
    EncounterEvent() = default;

    explicit EncounterEvent(int num_monster, double addition = 0, bool random_add = true, bool create_monster = true);

    EncounterEvent(int start, int end, double addition, bool random_add = true, bool create_monster = true);

    ~EncounterEvent() override;

    void operator()(Person *) override;

    void add_monster(Monster *);

protected:

    std::vector<Monster *> monster_list;
    const std::string event_message = "开始战斗";
};


class CleanBadBuffEvent : public Event {
public:
    void operator()(Person *) override;

protected:
    const std::string event_message = "清除所有负面效果";
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
    void operator()(Person *) override;

    uint hp = 0;
};

class RecoverEvent : public Event {
public:
    explicit RecoverEvent(SnapshotEvent *snapshot) : snapshot(snapshot) {};

    void operator()(Person *) override;

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
