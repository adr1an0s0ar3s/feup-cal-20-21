#include "Path.h"

Path::Path() {
    this->path = std::list<int>();
    this->length = 0;
}

Path::Path(std::list<int> path, double length) {
    this->path = path;
    this->length = length;
}

std::list<int> Path::getPath() const {
    return this->path;
}

double Path::getLength() const {
    return this->length;
}

void Path::addEdge(int nodeId) {
    this->path.push_back(nodeId);
}

Path operator+(Path left, const Path &right) {
    left.path.insert(left.path.end(), right.path.begin(), right.path.end());
    left.length += right.length;
    return left;
}
