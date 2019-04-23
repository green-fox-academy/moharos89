//
// Created by Bence on 2019.04.23..
//

#include "Garden.h"

Garden::Garden(std::string name) {
    setName(name);
    _plants = {};

}

void Garden::addPlant(Plant &plant) {
    _plants.push_back(&plant);
}

void Garden::watering(double water) {
    std::cout << "Watering with " << water << std::endl;
    int counter = 0;
    for (int i = 0; i < _plants.size(); i++) {
        if (_plants[i]->waterLevelIndicator() == 1) {
            counter += 1;
        }
    }
    for (int i = 0; i < _plants.size(); i++) {
        _plants[i]->getSomeWater(water / counter);
    }
    for (int i = 0; i < _plants.size(); i++) {
        _plants[i]->printWaterNeed(_plants[i]->waterLevelIndicator());
    }

}

void Garden::setName(std::string name) {
    _name = name;

}

void Garden::getGardenStatus() {
    for (int i = 0; i < _plants.size(); ++i) {
        _plants[i]->printWaterNeed(_plants[i]->waterLevelIndicator());
    }

}
