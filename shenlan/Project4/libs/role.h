//
// Created by shiby on 22-10-20.
//

#ifndef PROJECT4_ROLE_H
#define PROJECT4_ROLE_H

#include <iostream>
#include <utility>
#include <vector>

class Buff;

class LiveObject {

public:
    const std::string name;

    LiveObject(uint hp, uint atk, uint max_hp, std::string name) :
            hp(hp),
            atk(atk),
            max_hp(max_hp),
            name(std::move(name)) {}

    [[nodiscard]] bool is_dead() const;

    [[nodiscard]] std::string state() const;

    [[nodiscard]] uint get_atk() const;

    void attack(LiveObject *obj) const;

    void injure(uint harm);

protected:
    uint hp;
    uint atk;
    uint max_hp;
};

class Person : public LiveObject {

public:
    Person(uint hp, uint ack, uint exp, uint max_hp, uint max_exp, const std::string &name)
            : LiveObject(hp, ack, max_hp, name),
              exp(exp),
              max_exp(max_exp) {}

    virtual ~Person();

    void cure();

    void cure(uint blood);

    void cure(double percent);

    void add_exp(uint exp);

    [[nodiscard]] std::string get_exp() const;

    void add_buff(Buff &);

    void buff();


protected:
    unsigned int exp;
    unsigned int max_exp;
    std::vector<Buff *> buff_list;
};


class Explorer : public Person {

public:
    Explorer() :
            Person(100, 10, 0, 100, 10, "探险者") {}

    ~Explorer() override = default;
};


class Monster : public LiveObject {

public:
    explicit Monster(const std::string &name) : LiveObject(10, 5, 10, name) {};

    Monster(uint hp, uint atk, uint max_hp, const std::string &name) : LiveObject(hp, atk, max_hp, name) {};

    explicit Monster(double addition, const std::string &name) :
            LiveObject(u_int(addition * 10), u_int(addition * 5), uint(addition * 10), name) {};

};


class Boss : public Monster {

public:
    explicit Boss(const std::string &name) : Monster(40, 15, 40, name) {};
};

#endif //PROJECT4_ROLE_H
