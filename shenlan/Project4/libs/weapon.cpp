//
// Created by shiby on 22-10-27.
//

#include "weapon.h"
#include "role.h"
#include "utils.h"


void Weapon::attack(LiveObject *other) {

    if (owner == nullptr) {
        std::cout << "没有装备的武器不能发动攻击" << std::endl;
        return;
    }

    if (durability > 0) {
        other->injure(owner->get_atk() + atk);
        durability--;
    } else {
        other->injure(owner->get_atk());
    }
    if (durability == 0) {
        print_weapon_message(this);
    }
}

void Weapon::operator()(LiveObject *obj) {
    obj->wear(this);
}

std::ostream &operator<<(std::ostream &oss, const Weapon &obj) {
    oss << "武器: 攻击力:" << obj.atk << " 耐久度:" << obj.durability << " " << obj.property_message << "\n";
    return oss;
}


void Weapon2::attack(LiveObject *other) {
    if (owner == nullptr) {
        std::cout << "没有装备的武器不能发动攻击" << std::endl;
        return;
    }
    if (durability > 0) {
        other->injure(owner->get_atk() + durability);
        durability--;
    } else {
        other->injure(owner->get_atk());
    }
    if (durability == 0) {
        print_weapon_message(this);
    }
}


void Weapon3::attack(LiveObject *other) {
    if (owner == nullptr) {
        std::cout << "没有装备的武器不能发动攻击" << std::endl;
        return;
    }
    if (durability > 0) {
        if (random() % 2 == 0) {
            owner->add_atk(owner->get_atk());
            print_weapon_property_message(property_message, owner);
        }

        other->injure(owner->get_atk() + atk);
        durability--;
    } else {
        other->injure(owner->get_atk());
    }
    if (durability == 0) {
        print_weapon_message(this);
    }

}
