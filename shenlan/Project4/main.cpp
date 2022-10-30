//
// Created by shiby on 22-10-20.
//

#include "game.h"
#include "role.h"
#include "utils.h"
#include "room.h"


int main() {
    Explorer user;
    Game game(&user);
    game.run();
    game.print_count_info();

//    std::cout << "\n";
//    WeaponRoom room6;
//    room6(&user);
//
//
//    std::cout << "\n";
//    WeaponRoom room7;
//    room7(&user);


//    Campsite campsite;
//    campsite(&user);
//
//    std::cout << "\n";
//    Room room2;
//    room2(&user);
//
//    std::cout << "\n";
//    TrapRoom room4;
//    room4(&user);
//
//
//    std::cout << "\n";
//    Room room3;
//    room3(&user);
//
//    std::cout << "\n";
//    BoosRoom room5;
//    room5(&user);
//
//

//
//    std::cout << "\n";
//    BoosRoom room7;
//    room7(&user);

    return 0;
}