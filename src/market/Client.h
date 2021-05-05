#ifndef MARKET_ON_WHEELS_CLIENT_H
#define MARKET_ON_WHEELS_CLIENT_H

#include <string>
class Client {
private:
    int clientId;
    int nodeId;

    std::string name;

public:
    Client(int clientId, int nodeId, const std::string &name);

    int getClientId() const;
    int getNodeId() const;
    const std::string & getName() const;
};

#endif //MARKET_ON_WHEELS_CLIENT_H
