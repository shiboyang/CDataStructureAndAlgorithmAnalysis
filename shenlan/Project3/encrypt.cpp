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

    std::ifstream cb_ifs(codeBook);
    std::ifstream ifs(InputFileName, std::ios::binary);
    std::ofstream ofs(OutputFileName, std::ios::binary);
    char code;

    while (ifs.read(&code, sizeof code)) {
        auto num = encrypt256(code, cb_ifs);
        ofs.put(num);
    }

    return 0;
}



