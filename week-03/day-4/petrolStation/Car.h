//
// Created by Bence on 2019.04.18..
//
#include <iostream>
#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H


class Car {
public:
    Car (int gasAmount , int capacity);
    void setGasAmount(int gasAmount);
    void setCapacity(int capacity);
    const int getGasAmount() const;
    const int getCapacity() const;
    bool isFull();
    void fill();

private:
    int _gasAmount;
    int _capacity;
};


#endif //PETROLSTATION_CAR_H
