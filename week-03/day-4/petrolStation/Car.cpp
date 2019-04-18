//
// Created by Bence on 2019.04.18..
//

#include "Car.h"

Car::Car(int gasAmount, int capacity) {
    setGasAmount(gasAmount);
    setCapacity(capacity);

}

void Car::setGasAmount(int gasAmount) {
    _gasAmount = gasAmount;
}

void Car::setCapacity(int capacity) {
    _capacity = capacity;

}

const int Car::getGasAmount() const {
    return _gasAmount;
}

const int Car::getCapacity() const {
    return _capacity;
}

bool Car::isFull() {
    if (getGasAmount() == getCapacity()) {
        return true;
    } else {
        return false;
    }
}

void Car::fill() {
    _gasAmount += 1;

}
