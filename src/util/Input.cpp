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
    trimString(str);
    std::cout << std::endl;
    return str;
}

void trimString(std::string &str) {
    // Remove whitespace from start and end of the string
    auto front = std::find_if_not(str.begin(),str.end(),[](int c){
        return std::isspace(c);
    });
    auto back = std::find_if_not(str.rbegin(),str.rend(),[](int c){
        return std::isspace(c);
    }).base();
    str = back<=front ? std::string() : std::string(front, back);

    // Convert multiple whitespaces into a single one
    // For example "Avenida   dos      Aliados" would become "Avenida dos Aliados"
    auto new_end = std::unique(str.begin(), str.end(), [](char a, char b){
        return (a==b) && (a==' ');
    });
    str.erase(new_end, str.end());
}
