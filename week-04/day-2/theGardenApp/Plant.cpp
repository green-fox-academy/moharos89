//
// Created by Bence on 2019.04.23..
//

#include "Plant.h"

Plant::Plant() {
    setColor("black");
    setWaterLevel(rand());

}

Plant::Plant(std::string color, double waterLevel) {
    setColor(color);
    setWaterLevel(waterLevel);

}

void Plant::setColor(std::string color) {
    _color = color;

}

void Plant::setWaterLevel(double waterLevel) {
    _waterLevel = waterLevel;

}

const std::string Plant::getColor() const {
    return _color;
}

const double Plant::getWaterLevel() const {
    return _waterLevel;
}

void Plant::getSomeWater(double water) {
    _waterLevel += water;

}

bool Plant::waterLevelIndicator() {
    if (_waterLevel < 5) {
        return true;
    } else {
        return false;
    }
}

void Plant::printWaterNeed(bool waterNeed) {
    if (waterNeed == 1) {
        std::cout << "The " << _color << " Plant needs water" << std::endl;
    } else {
        std::cout << "The " << _color << " Plant doesnt need water" << std::endl;
    }

}

