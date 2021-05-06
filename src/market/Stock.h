#ifndef MARKET_ON_WHEELS_STOCK_H
#define MARKET_ON_WHEELS_STOCK_H

#include <map>

class Stock {
private:
    std::map<int, int> inventory;  // (Product Id, Quantity)

public:
    Stock();

    int getQuantity(int productId);

    void setQuantity(int productId, int quantity);
};

#endif //MARKET_ON_WHEELS_STOCK_H
