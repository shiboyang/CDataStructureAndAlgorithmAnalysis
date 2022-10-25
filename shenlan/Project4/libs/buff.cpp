//
// Created by shiby on 22-10-21.
//

#include "buff.h"
#include "role.h"

bool Buff::expired() const {
    return expire <= 0;
}

void LossBuff::operator()(Person *user) {
    if (expire-- > 0) {
        std::cout << message << ", " << user->state() << std::endl;
        user->injure(2);
    }
}

void CureBuff::operator()(Person *user) {
    if (expire-- > 0)
    {
        user->cure(hp);
        std::cout << message << ", " << user->state() << std::endl;
    }
}

