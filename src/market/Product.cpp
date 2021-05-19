#include "Product.h"

Product::Product() {
    this->productId = 0;
    this->name = "";
    this->weight = 0;
    this->cost = 0;
}

Product::Product(int productId, const std::string &name, double weight, double cost) {
    this->productId = productId;
    this->name = name;
    this->weight = weight;
    this->cost = cost;
}

int Product::getProductId() const {
    return this->productId;
}

const std::string &Product::getName() const {
    return this->name;
}

double Product::getWeight() const {
    return this->weight;
}

double Product::getCost() const {
    return this->cost;
}
