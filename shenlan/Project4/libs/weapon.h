//
// Created by shiby on 22-10-27.
//

#ifndef PROJECT4_WEAPON_H
#define PROJECT4_WEAPON_H


#include <cstdlib>
#include <string>
#include <utility>


class LiveObject;

class Weapon {
public:
    Weapon() : atk(4), durability(6), max_atk(4), max_durability(6) {};

    explicit Weapon(std::string msg) : atk(4), durability(6), max_atk(4), max_durability(6),
                                       property_message(std::move(msg)) {};

    Weapon(uint atk, uint durability, std::string msg) :
            atk(atk), durability(durability), max_atk(atk), max_durability(durability),
            property_message(std::move(msg)) {};

    virtual ~Weapon() = default;

    virtual void operator()(LiveObject *);

    virtual void attack(LiveObject *);

    friend std::ostream &operator<<(std::ostream &oss, const Weapon &);

    uint atk;
    uint durability;
    const uint max_atk;
    const uint max_durability;
    LiveObject *owner = nullptr;
protected:
    std::string property_message;

};

class Weapon2 : public Weapon {
public:
    Weapon2() : Weapon(0, 6, "") {};

    Weapon2(uint atk, uint durability) : Weapon(atk, durability, "") {}

    void attack(LiveObject *) override;
};


class Weapon3 : public Weapon {
public:
    Weapon3() : Weapon(1, 6, "属性:使用者攻击力永久翻倍") {};

    Weapon3(uint atk, uint durability) : Weapon(atk, durability, "属性:使用者攻击力永久翻倍") {};

    void attack(LiveObject *) override;
};


#endif //PROJECT4_WEAPON_H
