//
// Created by Bence on 2019.04.23..
//

#include "Tree.h"

Tree::Tree(std::string color, double waterLevel) : Plant(color, waterLevel) {
    setName();

}

void Tree::setName() {
    _name = getColor() + " Tree";

}

const std::string Tree::getName() const {
    return _name;
}

void Tree::getSomeWater(double water) {
    if (waterLevelIndicator() == 1) {
        _waterLevel += (water * 0.4);
    }
}

bool Tree::waterLevelIndicator() {
    if (_waterLevel < 10) {
        return true;
    } else {
        return false;
    }
}

void Tree::printWaterNeed(bool waterNeed) {
    if (waterNeed == 1) {
        std::cout << "The " << _name << " needs water" << std::endl;
    } else {
        std::cout << "The " << _name << " Plant doesnt need water" << std::endl;
    }
}
