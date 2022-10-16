//
// Created by shiby on 22-10-15.
//

#include "lib.h"

using std::string;

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Argument error\n" << "Usage: " << __func__ << " Codebook, inputFile, outputFile";
        exit(EXIT_FAILURE);
    }

    string codeBook = argv[1];
    string InputFileName = argv[2];
    string OutputFileName = argv[3];

    std::ifstream cv_ifs(codeBook);
    std::array<int, 256> codebook_array = read_codebook256(cv_ifs);

    std::ifstream ifs(InputFileName, std::ios::binary);
    std::ofstream ofs(OutputFileName, std::ios_base::binary);
    unsigned char code;

    while (ifs.read(reinterpret_cast<char *>(&code), sizeof code)) {
        auto num = encrypt(code, codebook_array);
        ofs.write(reinterpret_cast<char *>(&num), sizeof num);
    }

    return 0;
}



