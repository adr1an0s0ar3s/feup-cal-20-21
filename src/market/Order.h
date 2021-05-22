#ifndef MARKET_ON_WHEELS_ORDER_H
#define MARKET_ON_WHEELS_ORDER_H

#include "Client.h"
#include "Stock.h"

class Order {
private:
    int orderId;
    Client * owner;
    Stock products;

public:
    Order();
    Order(int orderId, Client * owner);

    int getOrderId() const;
    Client * getOwner() const;
    Stock & getProducts() const;

    bool operator<(const Order &o);
};

#endif //MARKET_ON_WHEELS_ORDER_H
