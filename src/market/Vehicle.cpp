#include "Vehicle.h"

Vehicle::Vehicle(int capacity) {
    this->capacity = capacity;
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
