//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_ROOM_H
#define PROJECT4_ROOM_H

#include <memory>

class Event;

class Buff;

class Person;

class BaseRoom {
public:
    virtual void operator()(Person *) = 0;

    virtual void encounter(Person *) = 0;

    virtual ~BaseRoom() = default;

protected:
    Event *enter_event = nullptr;
    Buff *enter_buff = nullptr;
    Event *encounter_event = nullptr;

};

class Campsite : public BaseRoom {
public:
    Campsite();

    ~Campsite() override;

    //enter event
    void operator()(Person *) override;

    //encounter event
    void encounter(Person *) override;

};

class Room : public BaseRoom {
public:
    Room();

    ~Room() override;

    void operator()(Person *) override;

    void encounter(Person *) override;
};

class Trap : public BaseRoom {
public:
    void operator()(Person *) override;
};

class BoosRoom : public BaseRoom {
public:
    void operator()(Person *) override;
};

class EquipmentRoom : public BaseRoom {
public:
    void operator()(Person *) override;
};


#endif //PROJECT4_ROOM_H
