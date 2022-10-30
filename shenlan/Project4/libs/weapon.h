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
    explicit Weapon(std::string name = "武器1", std::string msg = "") :
            atk(4), durability(6), max_atk(4), max_durability(6), name(std::move(name)),
            property_message(std::move(msg)) {};

    Weapon(uint atk, uint durability, std::string name, std::string msg) :
            atk(atk),
            max_atk(atk),
            durability(durability),
            max_durability(durability),
            property_message(std::move(msg)),
            name(std::move(name)) {};

    virtual ~Weapon() = default;

    virtual void operator()(LiveObject *);

    virtual uint attack(LiveObject *);

    friend std::ostream &operator<<(std::ostream &oss, const Weapon &);

    uint atk;
    uint durability;
    const uint max_atk;
    const uint max_durability;
    std::string name;
    LiveObject *owner = nullptr;
protected:
    std::string property_message;

};

class Weapon2 : public Weapon {
public:
    explicit Weapon2(std::string name = "武器2", std::string msg = "") :
            Weapon(0, 6, std::move(name), std::move(msg)) {};

    Weapon2(uint atk, uint durability, std::string name, std::string msg) :
            Weapon(atk, durability, std::move(name), std::move(msg)) {}

    uint attack(LiveObject *) override;
};


class Weapon3 : public Weapon {
public:
    explicit Weapon3(std::string name = "武器3", std::string msg = "属性:在攻击时50%攻击力永久翻倍") :
            Weapon(1, 6, std::move(name), std::move(msg)) {};

    uint attack(LiveObject *) override;
};


#endif //PROJECT4_WEAPON_H
