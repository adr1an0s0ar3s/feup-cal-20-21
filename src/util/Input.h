#ifndef MARKET_ON_WHEELS_INPUT_H
#define MARKET_ON_WHEELS_INPUT_H

#include <sstream>
#include "../market/Vehicle.h"
#include "../market/Order.h"

/**
 * @brief Waits for user to press Enter key
 */
void waitEnter();

/**
 * @brief Get a string from cin
 * @return string
 */
std::string getRaw();

/**
 * @brief Convert a string to a var of type T
 * @tparam T - Type with defined >> operator
 * @param str - String to be read
 * @param var - Output after reading
 * @return true if success
 */
template <typename T>
 bool strToVar(const std::string &str, T &var){
    std::istringstream ss{str};
    ss >> var;
    if(ss.fail() || !ss.eof()){
        return false;
    }
    return true;
}

/**
 * @brief Get a var of type T from cin
 * @tparam T - Type with defined >> operator
 * @param var - Output
 * @return true if success
 */
template <typename T>
bool get(T &var){
    std::string str = getRaw();
    if(str.empty()){
        return false;
    }
    return strToVar(str, var);
}

#endif //MARKET_ON_WHEELS_INPUT_H
