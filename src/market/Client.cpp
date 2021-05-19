#include "Client.h"

Client::Client() {
    this->clientId = 0;
    this->nodeId = 0;
    this->name = "";
}

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
