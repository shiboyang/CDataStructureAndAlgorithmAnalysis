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
    std::ifstream cb_ifs(codebook_path);
    if (!cb_ifs.is_open()) {
        std::cout << "Cannot open file" << codebook_path << std::endl;
        exit(EXIT_FAILURE);
    }

    string input_path = argv[2];
    std::ifstream ifs(input_path, std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "error" << std::endl;
    }

    string output_path = argv[3];
    std::ofstream ofs(output_path, std::ios::binary);

    char num;

    while (ifs >> num) {
        auto ch = decrypt256(num, cb_ifs);
        ofs.put(ch);
    }

    return 0;
}