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

    [[nodiscard]] bool is_dead() const;

    [[nodiscard]] std::string state() const;

    [[nodiscard]] uint get_atk() const;

    void gan(LiveObject *other) const;

    void injure(uint harm);

    [[nodiscard]] uint get_hp() const;

    void wear(Weapon *);

    [[nodiscard]] Weapon *takeoff(Weapon *);

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

    void cure();

    void cure(uint blood);

    void cure(double percent);

    void add_exp(uint exp);

    [[nodiscard]] std::string get_exp() const;

    void add_buff(Buff *);

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

//    ~Explorer() override = default;
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
};

#endif //PROJECT4_ROLE_H
