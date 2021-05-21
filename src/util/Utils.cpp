#include "Utils.h"

#include <cmath>

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2- y1, 2));
}

bool supplyProducts(std::vector<Order> &orders, Supplier &supplier) {
    bool supplied = false;
    int supplierRemovedQuantity, orderQuantity;
    for (Order &order : orders) {
        for (int productId : order.getProducts().getIds()) {
            orderQuantity = order.getProducts().getQuantity(productId);
            supplierRemovedQuantity = std::min(supplier.getStock().getQuantity(productId), orderQuantity);
            if (supplierRemovedQuantity > 0) {
                supplied = true;
                order.getProducts().setQuantity(productId, orderQuantity - supplierRemovedQuantity);
                supplier.getStock().setQuantity(productId, supplier.getStock().getQuantity(productId) - supplierRemovedQuantity);
            }
        }
    }
    return supplied;
}

bool deliverProducts(std::vector<Order> &orders, Client &client) {
    for (std::vector<Order>::iterator it = orders.begin(); it != orders.end(); ++it) {
        if (it->getOwner()->getClientId() == client.getClientId() && it->getProducts().isEmpty()) {
            orders.erase(it);
            return true;
        }
    }
    return false;
}
