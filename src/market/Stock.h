#ifndef MARKET_ON_WHEELS_STOCK_H
#define MARKET_ON_WHEELS_STOCK_H

#include "Product.h"

#include <map>
#include <vector>

/**
 * @brief Class that stores the id and quantity of the products
 */
class Stock {
private:

    std::map<int, int> inventory;  // (Product Id, Quantity)

public:

    /**
     * Class default constructor
     */
    Stock();

    /**
     * Gets the quantity of the given product
     * @param productId Id of the product to search
     * @return quantity of the given product
     */
    int getQuantity(int productId) const;

    /**
     * Gets the ids of the products
     * @return vector containing the id of the products
     */
    std::vector<int> getIds() const;

    /**
     * Sets the quantity of the given product to the given quantity
     * @param productId Id of the product to be changed
     * @param quantity New quantity
     */
    void setQuantity(int productId, int quantity);

    /**
     * Checks if there are no products
     * @return true if there are no products in stock
     */
    bool isEmpty();

    /**
     * Checks if the stock contains all of the products of other stock
     * @param stock Stock to be checked
     * @return true if the current stock contains the given stock
     */
    bool contains(const Stock &stock) const;

    /**
     * Overload of the += operator
     * @param s Right stock
     * @return New stock containing the sum
     */
    Stock &operator+=(const Stock &s);

    /**
     * Overload of the -= operator
     * @param s Right stock
     * @return New stock containing the subtraction
     */
    Stock &operator-=(const Stock &s);
};

#endif //MARKET_ON_WHEELS_STOCK_H
