#include "Path.h"

Path::Path() {
    this->path = std::vector<int>();
    this->length = 0;
}

Path::Path(std::vector<int> path, double length) {
    this->path = path;
    this->length = length;
}

std::vector<int> Path::getPath() const {
    return this->path;
}

double Path::getLength() const {
    return this->length;
}

void Path::addNode(int nodeId) {
    this->path.push_back(nodeId);
}
