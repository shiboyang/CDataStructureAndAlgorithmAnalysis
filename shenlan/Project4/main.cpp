//
// Created by shiby on 22-10-20.
//

#include "role.h"
#include "room.h"


int main() {
    Explorer user;
    Campsite campsite;
    campsite(&user);

//    std::cout << "\n";
//    Room room;
//    room(&user);
//    room.encounter(&user);

    std::cout << "\n";
    Room room2;
    room2(&user);

    std::cout << "\n";
    TrapRoom room4;
    room4(&user);


    std::cout << "\n";
    Room room3;
    room3(&user);

    std::cout << "\n";
    BoosRoom room5;
    room5(&user);


    std::cout << "\n";
    EquipmentRoom room6;
    room6(&user);


    return 0;
}