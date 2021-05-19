#ifndef MARKET_ON_WHEELS_VEHICLE_H
#define MARKET_ON_WHEELS_VEHICLE_H

class Vehicle {
private:
    int vehicleId;
    double capacity;

public:
    Vehicle();

    Vehicle(int vehicleId, double capacity);

    int getVehicleId() const;

    double getCapacity() const;

    void setCapacity(int newCapacity);

    bool operator<(const Vehicle &v) const;
};

#endif //MARKET_ON_WHEELS_VEHICLE_H
