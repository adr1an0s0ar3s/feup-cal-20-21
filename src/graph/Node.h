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
    Node(int nodeId, double x, double y) : nodeId(nodeId), x(x), y(y), client(nullptr), supplier(nullptr) {}
    double getX() const {return x;}
    double getY() const {return y;}
    void setClient(Client * client) {this->client = client;}
    void setSupplier(Supplier * supplier) {this->supplier = supplier;}
    friend bool operator==(const Node &n1, const Node &n2) {return n1.nodeId == n2.nodeId;}
};

#endif //MARKET_ON_WHEELS_NODE_H
