#ifndef MARKET_ON_WHEELS_STOCK_H
#define MARKET_ON_WHEELS_STOCK_H

#include "Product.h"

#include <map>
#include <vector>

class Stock {
private:
    std::map<int, int> inventory;  // (Product Id, Quantity)

public:
    Stock();

    int getQuantity(int productId) const;

    std::vector<int> getIds() const;

    void setQuantity(int productId, int quantity);

    bool isEmpty();

    int getSize();
};

#endif //MARKET_ON_WHEELS_STOCK_H
