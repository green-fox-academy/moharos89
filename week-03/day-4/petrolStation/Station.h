//
// Created by Bence on 2019.04.18..
//
#include <iostream>
#ifndef PETROLSTATION_STATION_H
#define PETROLSTATION_STATION_H

#include "Car.h"

class Station {
public:
    Station(int gasAmount);
    void fill(Car &car);
    void setGasAmount(int gasAmount);
    const int getGasAmount() const;

private:
    int _gasAmount;

};


#endif //PETROLSTATION_STATION_H
