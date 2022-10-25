//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_ROOM_H
#define PROJECT4_ROOM_H

#include <memory>
#include <utility>

class Event;

class Buff;

class Person;

class BaseRoom {
public:
    explicit BaseRoom(std::string name) : name(std::move(name)) {};

    BaseRoom(Event *enter_event, Buff *enter_buff, Event *encounter_event, std::string name) :
            enter_event(enter_event),
            enter_buff(enter_buff),
            encounter_event(encounter_event),
            name(std::move(name)) {};

    //enter event
    virtual void operator()(Person *);

    //encounter event
    virtual void encounter(Person *);

    virtual ~BaseRoom();

    void settle(Person *);

    const std::string name;

protected:
    Event *enter_event = nullptr;
    Buff *enter_buff = nullptr;
    Event *encounter_event = nullptr;

};

class Campsite : public BaseRoom {
public:
    explicit Campsite(const std::string &name = "营地房间");

    Campsite(Event *enter_event, Buff *enter_buff, Event *encounter_event, const std::string &name = "营地房间") :
            BaseRoom(enter_event, enter_buff, encounter_event, name) {};
};

class Room : public BaseRoom {
public:
    explicit Room(const std::string &name = "普通房间");

    Room(Event *enter_event, Buff *enter_buff, Event *encounter_event, const std::string &name = "普通房间") :
            BaseRoom(enter_event, enter_buff, encounter_event, name) {};
};

//class Trap : public BaseRoom {
//public:
//    void operator()(Person *) override;
//};
//
//class BoosRoom : public BaseRoom {
//public:
//    void operator()(Person *) override;
//};
//
//class EquipmentRoom : public BaseRoom {
//public:
//    void operator()(Person *) override;
//};


#endif //PROJECT4_ROOM_H
