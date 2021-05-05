#ifndef MARKET_ON_WHEELS_CLIENT_H
#define MARKET_ON_WHEELS_CLIENT_H

#include <string>
class Client {
private:
    int id;
    std::string name;
    int addressId;

public:
    Client(int id, const std::string &name, int addressId);
    int getId() const;
    const std::string & getName() const;
    int getAddressId() const;
};

#endif //MARKET_ON_WHEELS_CLIENT_H
