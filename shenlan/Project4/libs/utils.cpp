//
// Created by shiby on 22-10-21.
//

#include <random>
#include "utils.h"


int randint(int start, int end) {
    auto num = int(random() % end);
    num = (num < start) ? end - num : num;
    return num;
}

int randint(int value) {
    return int(random() % value);
}
