#include "Stock.h"

Stock::Stock() {
    this->inventory = std::map<int, int>();
    this->totalWeight = 0;
}

int Stock::getQuantity(int productId) const {
    int quantity;
    try {
        quantity = this->inventory.at(productId);
    }
    catch (std::out_of_range &e){
        return 0;
    }
    return quantity;
}

std::vector<int> Stock::getIds() const {
    std::vector<int> result(inventory.size());
    std::map<int, int>::const_iterator it = inventory.begin();
    for (int i = 0; it != inventory.end(); ++i, ++it) {
        result.at(i) = it->first;
    }
    return result;
}

double Stock::getTotalWeight() const {
    return this->totalWeight;
};

void Stock::setQuantity(int productId, int quantity, const std::vector<Product> &products) {
    std::pair<std::map<int, int>::iterator , bool> result = this->inventory.insert(std::pair<int, int> (productId, quantity));
    if (!result.second) {
        totalWeight += (quantity - result.first->second) * products[productId - 1].getWeight();
        result.first->second = quantity;
    }
    else {
        totalWeight += quantity * products[productId - 1].getWeight();
    }
    if (quantity == 0) inventory.erase(result.first);
}

bool Stock::isEmpty() {
    return this->inventory.empty();
}

Stock & Stock::operator+(const Stock &s) {
    for (int productId : s.getIds()) {
        this->setQuantity(productId, this->getQuantity(productId) + s.getQuantity(productId), products)
    }
}
