//
// Created by Bence on 2019.05.02..
//

#ifndef AIRCRAFT_AIRCRAFTCARRIER_H
#define AIRCRAFT_AIRCRAFTCARRIER_H

#include "aircraft.h"
#include <vector>

class AircraftCarrier {
public:
    AircraftCarrier();

    AircraftCarrier(int healthPoint , int amountOfAmmo);

    int getAmountOfAmmo() const;

    void setAmountOfAmmo(int amountOfAmmo);

    int getHealthPoint() const;

    void setHealthPoint(int healthPoint);

    void add(Aircraft *aircraft);

    const std::vector<Aircraft *> &getWarPlanes() const;

    void setWarPlanes(const std::vector<Aircraft *> &warPlanes);

    void fill();

    std::string status();

    void fight(AircraftCarrier *aircraftCarrier);

private:
    std::vector<Aircraft *> _warPlanes;
    int _amountOfAmmo;
    int _healthPoint;

};


#endif //AIRCRAFT_AIRCRAFTCARRIER_H
