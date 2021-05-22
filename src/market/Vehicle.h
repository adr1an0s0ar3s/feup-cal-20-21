#ifndef MARKET_ON_WHEELS_VEHICLE_H
#define MARKET_ON_WHEELS_VEHICLE_H

class Vehicle {
private:
    int vehicleId;
    double maxCapacity;

public:
    Vehicle();

    Vehicle(int vehicleId, double maxCapacity);

    int getVehicleId() const;

    double getMaxCapacity() const;

    void setMaxCapacity(int newCapacity);

    bool operator<(const Vehicle &v) const;
};

#endif //MARKET_ON_WHEELS_VEHICLE_H
