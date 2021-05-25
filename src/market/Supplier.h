#ifndef MARKET_ON_WHEELS_SUPPLIER_H
#define MARKET_ON_WHEELS_SUPPLIER_H

#include "Stock.h"

/**
 * @brief Class that holds information about a supplier
 */
class Supplier {
private:

    int supplierId;
    int nodeId;
    Stock stock;

public:

    /**
     * Class default constructor
     */
    Supplier();

    /**
     * Class constructor
     * @param supplierId Id of the supplier
     * @param nodeId Id of the node where the supplier is located
     */
    Supplier(int supplierId, int nodeId);

    /**
     * Gets the id of the supplier
     * @return id of the supplier
     */
    int getSupplierId() const;

    /**
     * Gets the id of the node where the supplier is located
     * @return id of the node
     */
    int getNodeId() const;

    /**
     * Gets the stock of the supplier
     * @return stock of the supplier
     */
    Stock & getStock() const;
};

#endif //MARKET_ON_WHEELS_SUPPLIER_H
