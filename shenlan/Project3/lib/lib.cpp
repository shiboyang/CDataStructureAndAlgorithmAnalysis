//
// Created by shiby on 22-10-15.
//
#include "lib.h"


char encrypt256(unsigned char code, std::ifstream &ifs) {
    //generate encrypted code list
    int ch;
    static std::array<char, 256> codebook{};
    int i = 0;
    while (ifs >> ch) {
        codebook[i++] = (char) ch;
    }
    return codebook[code];
}


char decrypt256(unsigned char code, std::ifstream &ifs) {
    int ch;
    static std::array<char, 256> decodebook{};
    int i = 0;
    while (ifs >> ch) {
        decodebook[ch] = (char) i++;
    }

    return decodebook[code];
}

char encrypt26(unsigned char ch, std::ifstream &cb_ifs) {
    static std::array<char, 26> codebook26{};
    char tmp;
    int i = 0;
    while (cb_ifs.read(&tmp, sizeof(tmp))) {
        codebook26[i++] = tmp;
    }
    return (ch > 'a' && ch < 'z') ? codebook26[ch - 'a'] : char(ch);
}

char decrypt26(unsigned char ch, std::ifstream &cb_ifs) {
    static std::array<char, 26> decodebook26{};
    char tmp;
    int i = 'a';
    while (cb_ifs.read(&tmp, sizeof tmp)) {
        decodebook26[tmp - 'a'] = char(i++);
    }
    return (ch > 'a' && ch < 'z') ? decodebook26[ch - 'a'] : char(ch);
}

