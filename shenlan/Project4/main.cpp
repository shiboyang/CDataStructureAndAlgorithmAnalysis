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

//    std::cout << user.is_dead() << std::endl;

    Room room;
    room(&user);
    room.encounter(&user);

    Room room2;
    room2(&user);
    room2.encounter(&user);


    Room room3;
    room3(&user);
    room3.encounter(&user);


    return 0;
}