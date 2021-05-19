#include "Input.h"

#include<iostream>
#include <algorithm>

void waitEnter() {
    std::cout << std::endl << "Press enter to continue..." << std::endl;
    std::string str;
    std::getline(std::cin, str);
}

std::string getRaw(){
    std::string str;
    std::cout << "> ";
    std::getline(std::cin, str);
    std::cout << std::endl;
    return str;
}
