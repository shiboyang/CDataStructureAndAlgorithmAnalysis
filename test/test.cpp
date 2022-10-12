//
// Created by shiby on 22-9-27.
//
#include <iostream>
#include <string>
#include <algorithm>


//void clean_string(const std::string &str) {
//    std::cout << str << std::endl;
//}




int main() {
    std::string str = "abcdefg--";

    auto is_lower_letters = [](char a) {
        return (a >= 'a' && a <= 'z');
    };
    auto ret = std::find_if_not(str.begin(), str.end(), is_lower_letters);
    std::cout << *ret << std::endl;
    return 0;
}