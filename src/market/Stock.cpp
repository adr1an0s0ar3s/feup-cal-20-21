#include "Stock.h"

Stock::Stock() {
    this->inventory = std::map<int, int>();
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

void Stock::setQuantity(int productId, int quantity) {
    std::pair<std::map<int, int>::iterator , bool> result = this->inventory.insert(std::pair<int, int> (productId, quantity));
    if (!result.second) result.first->second = quantity;
}

bool Stock::checkHasQuantity(int productId, int quantity) {
    for (const auto &s : this->inventory) {
        if (s.first == productId) {
            if (s.second >= quantity) return true;
            else return false;
        }
    }
    return false;
}
