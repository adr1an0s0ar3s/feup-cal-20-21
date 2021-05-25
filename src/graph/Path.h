#ifndef MARKET_ON_WHEELS_PATH_H
#define MARKET_ON_WHEELS_PATH_H

#include <list>

/**
 * @brief Class that stores edgeIDs that form a path
 */
class Path {

    std::list<int> path;

public:

    Path();
    Path(std::list<int> path);

    /**
     * @brief Returns a list with edge IDs
     * @return List with edge IDs
     */
    std::list<int> getPath() const;

    /**
     * @brief Adds an edge ID to the path
     * @param edgeID
     */
    void addEdge(int edgeID);

    /**
     * @brief
     * @param left
     * @param right
     * @return
     */
    friend Path operator+(Path left, const Path &right);
};

#endif //MARKET_ON_WHEELS_PATH_H
