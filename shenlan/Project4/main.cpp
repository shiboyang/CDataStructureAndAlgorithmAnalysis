//
// Created by shiby on 22-10-20.
//

#include "role.h"
#include "room.h"


int main() {
    Explorer user;
    Campsite campsite;
    campsite(&user);
    campsite.encounter(&user);

    Room room;
    room(&user);
    room.encounter(&user);

    return 0;
}