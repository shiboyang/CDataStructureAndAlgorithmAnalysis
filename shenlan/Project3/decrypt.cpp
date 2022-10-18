//
// Created by shiby on 22-10-15.
//

#include "lib.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Argument error\n" << "Usage: " << __func__ << " Codebook, EncryptFile, DecryptFile";
        exit(EXIT_FAILURE);
    }

    string codeBook = argv[1];
    string InputFileName = argv[2];
    string OutputFileName = argv[3];

    std::ifstream cb_ifs(codeBook, std::ios::ate);
    std::ifstream ifs(InputFileName, std::ios::binary);
    std::ofstream ofs(OutputFileName, std::ios::binary);

    char num;
    bool use26 = true;
    char ch;
    if (cb_ifs.tellg() > 26) use26 = false;
    cb_ifs.seekg(0);

    while (ifs.read(&num, sizeof num)) {
        if (use26)
            ch = decrypt26(num, cb_ifs);
        else
            ch = decrypt256(num, cb_ifs);
        ofs.write(&ch, 1);
    }

    return 0;
}