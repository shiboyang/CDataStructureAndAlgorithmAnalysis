//
// Created by shiby on 22-10-20.
//

#ifndef PROJECT3_ROLE_H
#define PROJECT3_ROLE_H

#include <iostream>

class LiveObject {

public:
    LiveObject(int hp, int ack) : hp(hp), atk(ack) {}

    int hp;
    int atk;

};

class Person : LiveObject {

public:
    Person(int hp, int ack, int exp)
            : LiveObject(hp, ack),
              exp(exp) {
        max_hp = 100;
        max_exp = 10;
    }

    int exp;

    virtual ~Person() = default;

protected:
    int max_hp;
    int max_exp;
};


class Pathfinder : public Person {

public:
    Pathfinder() :
            Person(100, 10, 0) {}
};


class Monster : public LiveObject {

public:
    Monster() :
            LiveObject(10, 5),
            max_hp(10),
            max_atk(5) {};
protected:
    const int max_hp;
    const int max_atk;
};

class Boss : public LiveObject {

public:
    Boss() :
            LiveObject(40, 15),
            max_hp(40),
            max_atk(15) {};
protected:
    const int max_hp;
    const int max_atk;
};

#endif //PROJECT3_ROLE_H
