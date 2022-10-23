//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_BUFFER_H
#define PROJECT4_BUFFER_H

#include <random>

class Person;

class Buff {

public:
    explicit Buff(int ex = 1) : expire(ex) {};

    virtual void operator()(Person *) = 0;

    virtual ~Buff() = default;

protected:
    int expire;
};


class LossBuff : Buff {
public:
    void operator()(Person *) override;
};


class CureBuff : public Buff {
public:
    explicit CureBuff(unsigned int hp, int ex = 1) : Buff(ex), hp(hp) {};

    void operator()(Person *) override;

protected:
    unsigned int hp = 0;
};

#endif //PROJECT4_BUFFER_H
