#include "Vehicle.h"

Vehicle::Vehicle() {
    this->vehicleId = 0;
    this->maxCapacity = 0;
}

Vehicle::Vehicle(int vehicleId, double maxCapacity) {
    this->vehicleId = vehicleId;
    this->maxCapacity = maxCapacity;
}

int Vehicle::getVehicleId() const {
    return this->vehicleId;
}

double Vehicle::getMaxCapacity() const {
    return this->maxCapacity;
}

void Vehicle::setMaxCapacity(int newCapacity) {
    this->maxCapacity = newCapacity;
}

bool Vehicle::operator<(const Vehicle &v) const {
    return this->maxCapacity > v.getMaxCapacity();
}
