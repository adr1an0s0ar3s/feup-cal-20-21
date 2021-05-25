#ifndef MARKET_ON_WHEELS_CLIENT_H
#define MARKET_ON_WHEELS_CLIENT_H

#include <string>

/**
 * @brief Class that holds information about a client
 */
class Client {
private:

    int clientId;
    int nodeId;
    std::string name;

public:

    /**
     * Class default constructor
     */
    Client();

    /**
     * Class constructor
     * @param clientId Id of the client
     * @param nodeId Id of the node where the client is located
     * @param name Name of the client
     */
    Client(int clientId, int nodeId, const std::string &name);

    /**
     * Gets the id of the client
     * @return id of the client
     */
    int getClientId() const;

    /**
     * Gets the id of the node where the client is located
     * @return id of the node where the client is located
     */
    int getNodeId() const;

    /**
     * Gets the name of the client
     * @return name of the client
     */
    const std::string & getName() const;
};

#endif //MARKET_ON_WHEELS_CLIENT_H
