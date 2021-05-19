#include "Supplier.h"

Supplier::Supplier() {
    this->supplierId = 0;
    this->nodeId = 0;
    this->stock = Stock();
}

Supplier::Supplier(int supplierId, int nodeId) {
    this->supplierId = supplierId;
    this->nodeId = nodeId;
    this->stock = Stock();
}

int Supplier::getSupplierId() const {
    return this->supplierId;
}

int Supplier::getNodeId() const {
    return this->nodeId;
}

Stock &Supplier::getStock() const {
    return (Stock &) (this->stock);
}
