//
// Created by shiby on 22-10-21.
//

#include "buff.h"
#include "role.h"


void LossBuff::operator()(Person *user) {
}

void CureBuff::operator()(Person *user) {
    if (this->expire > 0) {
        user->cure(this->hp);
        --this->expire;
    }
}
