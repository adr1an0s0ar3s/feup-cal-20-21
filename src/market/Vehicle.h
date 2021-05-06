#ifndef MARKET_ON_WHEELS_VEHICLE_H
#define MARKET_ON_WHEELS_VEHICLE_H

class Vehicle {
private:
    double capacity;

public:
    explicit Vehicle(int capacity);

    double getCapacity() const;

    void setCapacity(int newCapacity);

    bool operator<(const Vehicle &v) const;
};

#endif //MARKET_ON_WHEELS_VEHICLE_H
