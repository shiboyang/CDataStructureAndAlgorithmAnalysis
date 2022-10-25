//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_EVENT_H
#define PROJECT4_EVENT_H

#include <vector>
#include <memory>


class Person;

class Monster;

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


class RestoreHPEvent : public Event {
public:
    void operator()(Person *) override;

protected:
    const std::string event_message = "恢复探险者全部生命";
};


class EncounterEvent : public Event {
public:
    explicit EncounterEvent(int num_monster, double addition = 0, bool random_add = true);

    EncounterEvent(int start, int end, double addition = 1.0, bool random_add = true);

    ~EncounterEvent() override;

    void operator()(Person *) override;

protected:
    std::vector<Monster *> monster_list;
    const std::string event_message = "开始战斗";
};


#endif //PROJECT4_EVENT_H
