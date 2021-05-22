#ifndef MARKET_ON_WHEELS_STOCK_H
#define MARKET_ON_WHEELS_STOCK_H

#include "Product.h"

#include <map>
#include <vector>

class Stock {
private:
    std::map<int, int> inventory;  // (Product Id, Quantity)
    double totalWeight;

public:
    Stock();

    int getQuantity(int productId) const;

    double getTotalWeight() const;

    std::vector<int> getIds() const;

    void setQuantity(int productId, int quantity, const std::vector<Product> &products);

    bool isEmpty();

    Stock &operator+(const Stock &s);
};

#endif //MARKET_ON_WHEELS_STOCK_H
