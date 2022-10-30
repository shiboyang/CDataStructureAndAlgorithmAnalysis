//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_ROOM_H
#define PROJECT4_ROOM_H

#include <memory>
#include <vector>
#include <string>

class Event;

class Buff;

class Person;

class BaseRoom {
public:
    explicit BaseRoom(std::string name) : name(std::move(name)) {};

    virtual void operator()(Person *);

    virtual ~BaseRoom();

    const std::string name;
protected:
    std::vector<Event *> event_list;
};

class Campsite : public BaseRoom {
public:
    explicit Campsite(const std::string &name = "营地房间");
};

class Room : public BaseRoom {
public:
    explicit Room(const std::string &name = "普通房间");
};

class TrapRoom : public BaseRoom {
public:
    explicit TrapRoom(const std::string &name = "陷阱房间");
};

class BoosRoom : public BaseRoom {
public:
    explicit BoosRoom(const std::string &name = "领主房间");
};

class WeaponRoom : public BaseRoom {
public:
    explicit WeaponRoom(const std::string &name = "武器房间");
};


#endif //PROJECT4_ROOM_H
