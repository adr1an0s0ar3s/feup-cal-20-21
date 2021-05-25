#include "Path.h"

Path::Path() {
    this->path = std::list<int>();
}

Path::Path(std::list<int> path) {
    this->path = path;
}

std::list<int> Path::getPath() const {
    return this->path;
}

void Path::addEdge(int edgeID) {
    this->path.push_back(edgeID);
}

Path operator+(Path left, const Path &right) {
    left.path.insert(left.path.end(), right.path.begin(), right.path.end());
    return left;
}
