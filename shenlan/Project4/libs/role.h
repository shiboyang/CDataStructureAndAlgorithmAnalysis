//
// Created by shiby on 22-10-20.
//

#ifndef PROJECT4_ROLE_H
#define PROJECT4_ROLE_H

#include <iostream>
#include <vector>

class Buff;

class LiveObject {

public:
    LiveObject(unsigned int hp, unsigned int atk) : hp(hp), atk(atk) {}

protected:
    unsigned int hp;
    unsigned int atk;
};

class Person : LiveObject {

public:
    Person(unsigned int hp, unsigned int ack, unsigned int exp)
            : LiveObject(hp, ack),
              exp(exp) {}

    virtual ~Person();

    void cure();

    void cure(unsigned int hp);

    void cure(double percent);

    void add_buff(Buff &);


protected:
    unsigned int exp = 0;
    unsigned int max_hp = 0;
    unsigned int max_exp = 0;
    std::vector<Buff *> buff_list;
};


class Explorer : public Person {

public:
    Explorer() :
            Person(100, 10, 0) {}

    ~Explorer() override = default;

protected:
    const unsigned int max_hp = 100;
    const unsigned int max_exp = 10;
};


class Monster : public LiveObject {

public:
    Monster() :
            LiveObject(10, 5) {};

    explicit Monster(double addition) :
            LiveObject(u_int(addition * 10), u_int(addition * 5)) {};


protected:

    Monster(unsigned int hp, unsigned int atk) : LiveObject(hp, atk) {};

    const unsigned int max_hp = 10;
};


class Boss : public Monster {

public:
    Boss() : Monster(40, 15) {};

protected:
    const unsigned int max_hp = 40;
};

#endif //PROJECT4_ROLE_H
