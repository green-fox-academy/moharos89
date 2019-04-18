//
// Created by Bence on 2019.04.18..
//

#include "Station.h"

Station::Station(int gasAmount) {
    setGasAmount(gasAmount);

}

void Station::fill(Car &car) {
    if (car.isFull() == true) {
        std::cout << "Gas amount: " << getGasAmount() << std::endl;
    } else {
        car.fill();
        _gasAmount -= 1;
        std::cout << "Filling car!" << std::endl;
        Station::fill(car);

    }

}

void Station::setGasAmount(int gasAmount) {
    _gasAmount = gasAmount;

}

const int Station::getGasAmount() const {
    return _gasAmount;
}
