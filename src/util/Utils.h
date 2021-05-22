#ifndef MARKET_ON_WHEELS_UTILS_H
#define MARKET_ON_WHEELS_UTILS_H

#include "../market/Order.h"
#include "../market/Supplier.h"
#include "../market/Client.h"

#include <vector>
#include <stack>

double distance(double x1, double y1, double x2, double y2);

bool supplyProducts(std::vector<Order> &orders, Supplier *supplier, const std::vector<Product> &products);

bool deliverProducts(std::vector<Order> &orders, Client *client, const std::vector<Product> &products);

#endif //MARKET_ON_WHEELS_UTILS_H
