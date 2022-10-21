//
// Created by shiby on 22-10-21.
//

#ifndef PROJECT4_BUFFER_H
#define PROJECT4_BUFFER_H

#include "role.h"
#include <random>


class Buff {
public:
    virtual void operator()(Person &obj) = 0;
};

class GainBuff : Buff {
public:
    void operator()(Person &obj) override;
};

class LossBuff : Buff {
public:
    void operator()(Person &object) override;
};

#endif //PROJECT4_BUFFER_H
