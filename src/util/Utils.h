#ifndef MARKET_ON_WHEELS_UTILS_H
#define MARKET_ON_WHEELS_UTILS_H

#include "../market/Order.h"
#include "../market/Supplier.h"
#include "../market/Client.h"

#include <vector>
#include <stack>

/**
 * @brief Get euclidean distance between two points
 * @param x1 - x coordinate of point 1
 * @param y1 - y coordinate of point 1
 * @param x2 - x coordinate of point 2
 * @param y2 - y coordinate of point 2
 * @return distance between the two points
 */
double distance(double x1, double y1, double x2, double y2);

/**
 * @brief Supply products to orders
 * @param orders - Orders
 * @param supplier - Supplier
 * @return true if something was supplied
 */
bool supplyProducts(std::vector<Order> &orders, Supplier *supplier);

/**
 * @brief Deliver order to client
 * @param orders - Orders
 * @param client - Client to receive order
 * @return true if order was delivered
 */
bool deliverProducts(std::vector<Order> &orders, Client *client);

#endif //MARKET_ON_WHEELS_UTILS_H
