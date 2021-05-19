#include "Vehicle.h"

Vehicle::Vehicle() {
    this->vehicleId = 0;
    this->capacity = 0;
}

Vehicle::Vehicle(int vehicleId, double capacity) {
    this->vehicleId = vehicleId;
    this->capacity = capacity;
}

int Vehicle::getVehicleId() const {
    return this->vehicleId;
}

double Vehicle::getCapacity() const {
    return this->capacity;
}

void Vehicle::setCapacity(int newCapacity) {
    this->capacity = newCapacity;
}

bool Vehicle::operator<(const Vehicle &v) const {
    return this->capacity < v.getCapacity();
}
