//
// Created by shiby on 22-10-29.
//

#include <sstream>
#include "game.h"
#include "utils.h"
#include "room.h"
#include "role.h"


void Game::run() {
    BaseRoom *room;

    while (!user->is_dead()) {
        auto num = randint(100);
        if (num <= 10) {
            room = new Campsite;
        } else if (num <= 65) {
            room = new Room;
        } else if (num <= 80) {
            room = new TrapRoom;
        } else if (num <= 90) {
            room = new BoosRoom;
        } else {
            room = new WeaponRoom;
        }
        room_list.push_back(room);
        (*room)(user);
    }
}

Game::~Game() {
    for (auto r: room_list) {
        delete r;
    }
}

void Game::print_count_info() {
    std::string name[] = {"普通房间", "陷阱房间", "首领房间", "武器房间", "营地房间"};
    for (const auto &x: name) {
        count_info[x] = 0;
    }
    for (auto x: room_list) {
        count_info[x->name] += 1;
    }
    std::ostringstream oss;
    int count = 0;
    for (const auto &x: count_info) {
        oss << x.first << ":" << x.second << " ";
        count += x.second;
    }
    std::cout << "共走过" << count << "个房间, " << oss.str() << std::endl;
}

