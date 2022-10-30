//
// Created by shiby on 22-10-21.
//

#include "buff.h"
#include "role.h"

bool Buff::expired() const {
    return expire <= 0;
}

bool Buff::is_good() const {
    return type == goodBuff;
}

void LossHPBuff::operator()(Person *user) {
    if (expire-- > 0) {
        user->injure(2);
        std::cout << "触发" << message << ", " << user->state() << std::endl;
    }
}

void CureBuff::operator()(Person *user) {
    if (expire-- > 0) {
        user->cure(hp);
        std::cout << "触发" << message << ", " << user->state() << std::endl;
    }
}

