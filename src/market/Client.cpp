#include "Client.h"

Client::Client(int clientId, int nodeId, const std::string &name) {
    this->clientId = clientId;
    this->nodeId = nodeId;
    this->name = name;
}

int Client::getClientId() const {
    return this->clientId;
}

int Client::getNodeId() const {
    return this->nodeId;
}

const std::string &Client::getName() const {
    return this->name;
}
