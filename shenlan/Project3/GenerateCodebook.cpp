//
// Created by shiby on 22-10-15.
//
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <array>
#include <random>
#include <algorithm>

int main()
{

	std::ofstream ofs("codebook.txt");
	std::array<int, 256> codebook{};

	for (int i = 0; i<256; ++i) {
		codebook[i] = i;
	}


	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(codebook.begin(), codebook.end(), g);

	std::copy(codebook.begin(), codebook.end(), std::ostream_iterator<int>(ofs, " "));

	return 0;
}

