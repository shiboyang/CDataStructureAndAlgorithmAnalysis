//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_BUFFER_H
#define PROJECT4_BUFFER_H

#include <random>

enum BuffType {
    goodBuff,
    badBuff
};

class Person;

class Buff {

public:
    explicit Buff(BuffType type, const int ex = 1) : expire(ex), type(type) {};

    virtual void operator()(Person *) = 0;

    virtual ~Buff() = default;

    bool expired() const;

protected:
    int expire;
    BuffType type;
};


class LossBuff : Buff {
public:
    LossBuff() : Buff(badBuff) {};

    void operator()(Person *) override;

protected:
    const std::string message = "持续损伤效果, 失去2点生命";
};


class CureBuff : public Buff {
public:
    explicit CureBuff(uint hp, const int ex = 1) : Buff(goodBuff, ex), hp(hp) {};

    void operator()(Person *) override;

protected:
    unsigned int hp = 0;
    const std::string message = "持续治疗效果, 恢复5点生命";
};

#endif //PROJECT4_BUFFER_H
