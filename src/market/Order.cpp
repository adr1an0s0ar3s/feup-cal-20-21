#include "Order.h"

Order::Order() {
    this->orderId = 0;
    this->owner = nullptr;
}

Order::Order(int orderId, Client * owner) {
    this->orderId = orderId;
    this->owner = owner;
}

int Order::getOrderId() const {
    return this->orderId;
}

Client *Order::getOwner() const {
    return this->owner;
}

Stock &Order::getProducts() const {
    return (Stock &) (this->products);
}
