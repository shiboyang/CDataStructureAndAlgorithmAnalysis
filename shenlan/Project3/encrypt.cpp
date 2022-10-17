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

    std::ifstream cb_ifs(codeBook, std::ios::ate);
    std::ifstream ifs(InputFileName, std::ios::binary);
    std::ofstream ofs(OutputFileName, std::ios::binary);
    char code;
    bool use26 = true;
    char num;
    if (cb_ifs.tellg() > 26) use26 = false;
    cb_ifs.seekg(0);

    while (ifs.read(&code, sizeof code)) {
        if (use26)
            num = encrypt26(code, cb_ifs);
        else
            num = encrypt256(code, cb_ifs);
        ofs.write(&num, 1);
    }

    return 0;
}



