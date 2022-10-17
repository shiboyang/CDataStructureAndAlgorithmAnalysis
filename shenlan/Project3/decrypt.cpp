//
// Created by shiby on 22-10-15.
//

#include "lib.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Argument error\n" << "Usage: " << __func__ << " Codebook, EncryptFile, DecryptFile";
        exit(EXIT_FAILURE);
    }
    string codebook_path = argv[1];
    std::ifstream cb_ofs(codebook_path);
    if (!cb_ofs.is_open()) {
        std::cout << "Cannot open file" << codebook_path << std::endl;
        exit(EXIT_FAILURE);
    }

    string filename = argv[2];
    std::ifstream ifs(filename, std::ios_base::binary);

    string output_path = argv[3];
    std::ofstream ofs(output_path, std::ios_base::binary);

    auto codebook_array = read_codebook256(cb_ofs);
    int num;

    while (ifs.read(reinterpret_cast<char *>(&num), sizeof num)) {
        auto ch = decrypt(num, codebook_array);
        ofs.put(ch);
    }

    return 0;
}