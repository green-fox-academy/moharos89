//
// Created by Bence on 2019.04.23..
//

#include "Flower.h"

Flower::Flower(std::string color, double waterLevel) : Plant(color, waterLevel) {
    setName();
}

void Flower::setName() {
    _name = getColor() + " Flower";
}

const std::string Flower::getname() {
    return _name;
}

void Flower::getSomeWater(double water) {
    if (waterLevelIndicator() == 1) {
        _waterLevel += (water * 0.75);
    }
}

void Flower::printWaterNeed(bool waterNeed) {
    if (waterNeed == 1) {
        std::cout << "The " << _name << " needs water" << std::endl;
    } else {
        std::cout << "The " << _name << " Plant doesnt need water" << std::endl;
    }
}
