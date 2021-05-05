#include "Client.h"

Client::Client(int id, const std::string &name, int addressId) {
    this->id = id;
    this->name = name;
    this->addressId = addressId;
}

int Client::getId() const {
    return this->id;
}

const std::string &Client::getName() const {
    return this->name;
}

int Client::getAddressId() const {
    return this->addressId;
}
