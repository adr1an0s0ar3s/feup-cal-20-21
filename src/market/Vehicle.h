#ifndef MARKET_ON_WHEELS_VEHICLE_H
#define MARKET_ON_WHEELS_VEHICLE_H

class Vehicle {
    int capacity;

public:
    explicit Vehicle(int capacity);
    int getCapacity() const;
    void setCapacity(int newCapacity);
    bool operator<(const Vehicle &v) const;
};

#endif //MARKET_ON_WHEELS_VEHICLE_H
