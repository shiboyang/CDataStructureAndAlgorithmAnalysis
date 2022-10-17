//
// Created by shiby on 22-10-15.
//

#ifndef PROJ3_LIB_H
#define PROJ3_LIB_H

#include <iostream>
#include <fstream>
#include <array>
#include <sstream>

using std::string;

char encrypt256(unsigned char code, std::ifstream &ifs);

char decrypt256(unsigned char code, std::ifstream &ifs);


#endif //PROJ3_LIB_H
