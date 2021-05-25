#ifndef MARKET_ON_WHEELS_ORDER_H
#define MARKET_ON_WHEELS_ORDER_H

#include "Client.h"
#include "Stock.h"

/**
 * @brief Class that holds information about an order
 */
class Order {
private:

    int orderId;
    Client * owner;
    Stock products;

public:

    /**
     * Class default constructor
     */
    Order();
    /**
     * Class constructor
     * @param orderId Id of the order
     * @param owner Pointer to the client that owns the order
     */
    Order(int orderId, Client * owner);

    /**
     * Gets the id of the order
     * @return id of the order
     */
    int getOrderId() const;

    /**
     * Gets the owner of the order
     * @return owner of the order
     */
    Client * getOwner() const;

    /**
     * Get the products of the order
     * @return stock containing the products of the order
     */
    Stock & getProducts() const;
};

#endif //MARKET_ON_WHEELS_ORDER_H
