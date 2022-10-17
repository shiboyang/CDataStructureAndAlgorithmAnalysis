//
// Created by shiby on 22-10-15.
//
#include "lib.h"


char encrypt256(unsigned char code, std::ifstream &ifs) {
    //generate encrypted code list
    int ch;
    static std::array<char, 256> codebook;
    int i = 0;
    while (ifs >> ch) {
        codebook[i++] = (char) ch;
    }
    return codebook[code];
}


char decrypt256(unsigned char code, std::ifstream &ifs) {
    int ch;
    static std::array<char, 256> decodebook;
    int i = 0;
    while (ifs >> ch) {
        decodebook[code] = char(i++);
    }
    return decodebook[code];
}

