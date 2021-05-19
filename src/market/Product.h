#ifndef MARKET_ON_WHEELS_PRODUCT_H
#define MARKET_ON_WHEELS_PRODUCT_H

#include <string>

class Product {
private:
    int productId;
    std::string name;
    double weight;
    double cost;

public:
    Product();
    Product(int productId, const std::string & name, double weight, double cost);

    int getProductId() const;
    const std::string & getName() const;
    double getWeight() const;
    double getCost() const;
};

#endif //MARKET_ON_WHEELS_PRODUCT_H
