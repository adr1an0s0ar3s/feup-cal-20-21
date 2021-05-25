#ifndef MARKET_ON_WHEELS_VEHICLE_H
#define MARKET_ON_WHEELS_VEHICLE_H


/**
 * @brief Class that holds information about a vehicle
 */
class Vehicle {
private:

    int vehicleId;
    double maxCapacity;

public:

    /**
     * Class default constructor
     */
    Vehicle();

    /**
     * Class constructor
     * @param vehicleId Id of the vehicle
     * @param capacity Max capacity of the vehicle
     */
    Vehicle(int vehicleId, double maxCapacity);

    /**
     * Gets the id of the vehicle
     * @return id of the vehicle
     */
    int getVehicleId() const;

    /**
     * Gets the max capacity of the vehicle
     * @return max capacity of the vehicle
     */
    double getMaxCapacity() const;

    /**
     * Sets the max capacity of the vehicle to the given one
     * @param newCapacity New max capacity
     */
    void setMaxCapacity(int newCapacity);

    /**
     * Overload of the < operator
     * @param v vehicle to be compared with
     * @return true if the current vehicle is lower than the other
     */
    bool operator<(const Vehicle &v) const;
};

#endif //MARKET_ON_WHEELS_VEHICLE_H
