//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_BUFFER_H
#define PROJECT4_BUFFER_H

#include <string>
#include <utility>


enum BuffType {
    goodBuff,
    badBuff
};

class Person;

class Buff {

public:
    const std::string message;

    explicit Buff(BuffType type, const int ex, std::string msg = "") :
            expire(ex), type(type), message(std::move(msg)) {};

    virtual void operator()(Person *) = 0;

    virtual ~Buff() = default;

    [[nodiscard]] bool expired() const;

    [[nodiscard]] bool is_good() const;

protected:
    int expire;
    BuffType type;

};


class LossHPBuff : public Buff {
public:
    explicit LossHPBuff(const int ex = 1, std::string msg = "持续损伤效果, 失去2点生命") :
            Buff(badBuff, ex, std::move(msg)) {};

    void operator()(Person *) override;

};


class CureBuff : public Buff {
public:
    explicit CureBuff(uint hp, const int ex = 1, std::string msg = "持续治疗效果, 恢复5点生命")
            : Buff(goodBuff, ex, std::move(msg)), hp(hp) {};

    void operator()(Person *) override;

protected:
    unsigned int hp = 0;
};

#endif //PROJECT4_BUFFER_H
