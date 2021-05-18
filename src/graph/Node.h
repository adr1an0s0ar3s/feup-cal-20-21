#ifndef MARKET_ON_WHEELS_NODE_H
#define MARKET_ON_WHEELS_NODE_H

#include "../market/Client.h"
#include "../market/Supplier.h"

class Node {
private:
    double x;
    double y;
    int nodeId;
    Client * client;
    Supplier * supplier;
public:
    Node(int nodeId, int x, int y) : nodeId(nodeId), x(x), y(y), client(nullptr), supplier(nullptr) {}
    void setClient(Client * client) {this->client = client;}
    void setSupplier(Supplier * supplier) {this->supplier = supplier;}
};

#endif //MARKET_ON_WHEELS_NODE_H
