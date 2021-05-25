#ifndef MARKET_ON_WHEELS_PRODUCT_H
#define MARKET_ON_WHEELS_PRODUCT_H

#include <string>

/**
 * @brief Class that holds information about a product
 */
class Product {
private:

    int productId;
    std::string name;
    double weight;
    double cost;

public:

    /**
     * Class default constructor
     */
    Product();

    /**
     * Class constructor
     * @param productId Id of the product
     * @param name Name of the product
     * @param weight Weight of the product
     * @param cost Cost of the product
     */
    Product(int productId, const std::string & name, double weight, double cost);

    /**
     * Gets the id of the product
     * @return id of the product
     */
    int getProductId() const;

    /**
     * Gets the name of the product
     * @return name of the product
     */
    const std::string & getName() const;

    /**
     * Gets the weight of the product
     * @return weight of the product
     */
    double getWeight() const;

    /**
     * Gets the cost of the product
     * @return cost of the product
     */
    double getCost() const;
};

#endif //MARKET_ON_WHEELS_PRODUCT_H
