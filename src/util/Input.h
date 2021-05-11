#ifndef MARKET_ON_WHEELS_INPUT_H
#define MARKET_ON_WHEELS_INPUT_H

#include <sstream>
#include "../market/Vehicle.h"
#include "../market/Order.h"

void waitEnter();
std::string getRaw();
void trimString(std::string &str);

template <typename T>
bool strToVar(const std::string &str, T &var){
    std::istringstream ss{str};
    ss >> var;
    if(ss.fail() || !ss.eof()){
        return false;
    }
    return true;
}

template <typename T>
bool get(T &var){
    std::string str = getRaw();
    if(str.empty()){
        return false;
    }
    return strToVar(str, var);
}

#endif //MARKET_ON_WHEELS_INPUT_H
