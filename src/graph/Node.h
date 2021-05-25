#ifndef MARKET_ON_WHEELS_NODE_H
#define MARKET_ON_WHEELS_NODE_H

#include "../market/Client.h"
#include "../market/Supplier.h"

/**
 * @brief Class that stores all the needed information of a Node
 */
class Node {
private:

    float x;
    float y;
    int nodeId;
    Client * client;
    Supplier * supplier;

public:

    Node(int nodeId, float x, float y) : nodeId(nodeId), x(x), y(y), client(nullptr), supplier(nullptr) {}

    /**
     * @brief Returns the x coordinate of the node
     * @return float, the x coordinate
     */
    float getX() const {return x;}

    /**
     * @brief Returns the y coordinate of the node
     * @return float, the y coordinate
     */
    float getY() const {return y;}

    /**
     * @brief Returns the ID of the node
     * @return int, the ID
     */
    int getNodeId() const {return nodeId;}

    /**
     * @brief Return the client pointer of the node
     * @return Client pointer, nullptr if nonexistent
     */
    Client * getClient() const {return client;}

    /**
     * @brief Return the supplier pointer of the node
     * @return Supplier pointer, nullptr if nonexistent
     */
    Supplier * getSupplier() const {return supplier;}

    /**
     * @brief Sets the client pointer of the node
     * @param client The new client pointer
     */
    void setClient(Client * client) {this->client = client;}

    /**
     * @brief Sets the supplier pointer of the node
     * @param supplier The new supplier pointer
     */
    void setSupplier(Supplier * supplier) {this->supplier = supplier;}

    /**
     * @brief Compares two nodes
     * @param n1 The left node of the comparison
     * @param n2 The right node of the comparison
     * @return True if they're equal, False otherwise
     */
    friend bool operator==(const Node &n1, const Node &n2) {return n1.nodeId == n2.nodeId;}
};

#endif //MARKET_ON_WHEELS_NODE_H
