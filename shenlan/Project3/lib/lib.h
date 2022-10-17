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

std::array<int, 256> read_codebook256(std::ifstream &ifs);

int encrypt(unsigned char code, std::array<int, 256> &codebook_array);

char decrypt(int code, std::array<int, 256> &codebook_array);

int find_code(int num, std::array<int, 256> &codebook_array);


#endif //PROJ3_LIB_H
