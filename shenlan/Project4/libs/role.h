//
// Created by shiby on 22-10-20.
//

#ifndef PROJECT4_ROLE_H
#define PROJECT4_ROLE_H

#include <iostream>
#include <utility>
#include <list>

class Buff;

class Weapon;

class LiveObject {

public:
    const std::string name;

    LiveObject(uint hp, uint atk, uint max_hp, std::string name) :
            hp(hp),
            atk(atk),
            max_hp(max_hp),
            name(std::move(name)) {}

    virtual ~LiveObject();

    void cure();

    void cure(uint blood);

    void cure(double percent);

    [[nodiscard]] bool is_dead() const;

    [[nodiscard]] std::string state() const;

    [[nodiscard]] uint get_atk() const;

    uint gan(LiveObject *other);

    virtual void fight(LiveObject *other);

    void injure(uint harm);

    [[nodiscard]] uint get_hp() const;

    void wear(Weapon *);

    void takeoff();

    void add_atk(uint atk);

protected:
    uint hp;
    uint atk;
    uint max_hp;
    Weapon *weapon = nullptr;
};

class Person : public LiveObject {

public:
    Person(uint hp, uint ack, uint exp, uint max_hp, uint max_exp, const std::string &name)
            : LiveObject(hp, ack, max_hp, name),
              exp(exp),
              max_exp(max_exp) {}

    ~Person() override;

    void add_exp(uint exp);

    [[nodiscard]] uint get_exp() const;

    [[nodiscard]] uint get_max_exp() const;

    void add_buff(Buff *);

    void upgrade();

    void buff();

    std::list<Buff *> buff_list;
protected:
    unsigned int exp;
    unsigned int max_exp;
};


class Explorer : public Person {

public:
    Explorer() :
            Person(100, 10, 0, 100, 10, "探险者") {}

};


class Monster : public LiveObject {

public:
    explicit Monster(const std::string &name) : LiveObject(10, 5, 10, name) {};

    Monster(uint hp, uint atk, uint max_hp, const std::string &name) : LiveObject(hp, atk, max_hp, name) {};

    Monster(double addition, const std::string &name) :
            LiveObject(uint(addition * 10), uint(addition * 5), uint(addition * 10), name) {};

};


class Boss : public Monster {

public:
    explicit Boss(const std::string &name) : Monster(40, 15, 40, name) {};

    Boss(double addition, const std::string &name) :
            Monster(uint(addition * 40), uint(addition * 15), uint(addition * 40), name) {};

    void fight(LiveObject *other) override;

protected:
    bool have_cure = false;
};

#endif //PROJECT4_ROLE_H
