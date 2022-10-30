//
// Created by shiby on 22-10-27.
//

#include "weapon.h"
#include "role.h"
#include "utils.h"


uint Weapon::attack(LiveObject *other) {

    uint harm = 0;
    if (owner == nullptr) {
        std::cout << "没有装备的武器不能发动攻击" << std::endl;
        return harm;
    }

    if (durability > 0) {
        harm = owner->get_atk() + atk;
        other->injure(harm);
        durability--;
    } else {
        harm = owner->get_atk();
        other->injure(harm);
    }
    return harm;
}

void Weapon::operator()(LiveObject *obj) {
    obj->wear(this);
}

std::ostream &operator<<(std::ostream &oss, const Weapon &obj) {
    oss << obj.name << ": 攻击力:" << obj.atk << " 耐久度:" << obj.durability;
    if (!obj.property_message.empty())
        oss << " " << obj.property_message;
    return oss;
}


uint Weapon2::attack(LiveObject *other) {
    uint harm = 0;
    if (owner == nullptr) {
        std::cout << "没有装备的武器不能发动攻击" << std::endl;
        return harm;
    }
    if (durability > 0) {
        harm = owner->get_atk() + durability;
        other->injure(harm);
        durability--;
    } else {
        harm = owner->get_atk();
        other->injure(harm);
    }
    return harm;
}


uint Weapon3::attack(LiveObject *other) {
    uint harm = 0;
    if (owner == nullptr) {
        std::cout << "没有装备的武器不能发动攻击" << std::endl;
        return harm;
    }
    if (durability > 0) {
        if (randint(0, 1) == 0) {
            owner->add_atk(owner->get_atk());
            print_weapon_property_message(property_message, owner);
        }
        harm = owner->get_atk() + atk;
        other->injure(harm);
        durability--;
    } else {
        harm = owner->get_atk();
        other->injure(harm);
    }
    return harm;

}
