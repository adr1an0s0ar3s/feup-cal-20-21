#include "Input.h"

#include<iostream>
#include<vector>

bool allVehiclesFull(std::vector<Vehicle*>& vehicles) {
    for (Vehicle *v : vehicles) {

    }
    return true;
}

void waitEnter() {
    std::cout << std::endl << "Press enter to continue..." << std::endl;
    std::string str;
    std::getline(std::cin, str);
}
