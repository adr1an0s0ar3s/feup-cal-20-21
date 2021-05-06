#ifndef MARKET_ON_WHEELS_SUPPLIER_H
#define MARKET_ON_WHEELS_SUPPLIER_H

#include "Stock.h"

class Supplier {
private:
    int supplierId;
    int nodeId;

    Stock stock;

public:
    Supplier(int supplierId, int nodeId);

    int getSupplierId() const;
    int getNodeId() const;
    Stock & getStock() const;
};

#endif //MARKET_ON_WHEELS_SUPPLIER_H
