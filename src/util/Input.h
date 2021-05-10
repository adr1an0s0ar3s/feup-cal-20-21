#ifndef MARKET_ON_WHEELS_INPUT_H
#define MARKET_ON_WHEELS_INPUT_H

#include "../market/Vehicle.h"
#include "../market/Order.h"

#include <vector>

bool allVehiclesFull(std::vector<Vehicle*>& vehicles);
void waitEnter();

#endif //MARKET_ON_WHEELS_INPUT_H
