#ifndef MARKET_ON_WHEELS_PATH_H
#define MARKET_ON_WHEELS_PATH_H

#include <vector>

class Path {
    std::vector<int> path;
    double length;

public:
    Path();
    Path(std::vector<int> path, double length);

    std::vector<int> getPath() const;
    double getLength() const;
    void addNode(int nodeId);
};

#endif //MARKET_ON_WHEELS_PATH_H
