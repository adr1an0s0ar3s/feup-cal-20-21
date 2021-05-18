#ifndef MARKET_ON_WHEELS_STOCK_H
#define MARKET_ON_WHEELS_STOCK_H

#include "Product.h"

#include <map>

class Stock {
private:
    std::map<int, int> inventory;  // (Product Id, Quantity)

public:
    Stock();

    int getQuantity(int productId) const;

    void setQuantity(int productId, int quantity);

    bool checkHasQuantity(int productId, int quantity);
};

#endif //MARKET_ON_WHEELS_STOCK_H
