//
// Created by shiby on 22-10-29.
//

#ifndef PROJECT4_GAME_H
#define PROJECT4_GAME_H

#include <vector>
#include <map>
#include <string>


class Explorer;

class BaseRoom;


class Game {
    Explorer *user;
    std::vector<BaseRoom *> room_list;
    std::map<std::string, int> count_info;

public:

    explicit Game(Explorer *user) : user(user) {};

    ~Game();

    void run();

    void print_count_info();
};


#endif //PROJECT4_GAME_H
