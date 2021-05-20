#ifndef MARKET_ON_WHEELS_PATH_H
#define MARKET_ON_WHEELS_PATH_H

#include <list>

class Path {
    std::list<int> path;
    double length;

public:
    Path();
    Path(std::list<int> path, double length);

    std::list<int> getPath() const;
    double getLength() const;
    void addEdge(int nodeId);
};

#endif //MARKET_ON_WHEELS_PATH_H
