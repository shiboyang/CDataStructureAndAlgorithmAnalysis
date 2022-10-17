//
// Created by shiby on 22-10-15.
//
#include "lib.h"

std::array<int, 256> read_codebook256(std::ifstream &ifs) {
    std::array<int, 256> arr{};
    std::istringstream iss;
    int i = 0;
    int code;
    string str;
    getline(ifs, str);
    iss.str(str);
    while (iss >> code)
        arr[i++] = code;
    return arr;
}

int encrypt(unsigned char code, std::array<int, 256> &codebook_array) {
    return codebook_array[code];
}

char decrypt(int code, std::array<int, 256> &codebook_array) {
    auto index = find_code(code, codebook_array);
    if (index != -1)
        return char(index);
    std::cout << "decrypt error" << code << std::endl;
    exit(EXIT_FAILURE);
}

int find_code(int num, std::array<int, 256> &codebook_array) {
    int ret = -1;
    for (int i = 0; i < codebook_array.size(); ++i) {
        if (codebook_array[i] == num) {
            ret = i;
            break;
        }
    }
    return ret;
}
