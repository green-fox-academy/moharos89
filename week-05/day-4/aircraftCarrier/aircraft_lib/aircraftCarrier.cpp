//
// Created by Bence on 2019.05.02..
//

#include "aircraftCarrier.h"

AircraftCarrier::AircraftCarrier()
{
    setHealthPoint(2000);
    setAmountOfAmmo(300);
}

AircraftCarrier::AircraftCarrier(int healthPoint, int amountOfAmmo)
{
    setHealthPoint(healthPoint);
    setAmountOfAmmo(amountOfAmmo);
}

const std::vector<Aircraft> &AircraftCarrier::getWarPlanes() const
{
    return _warPlanes;
}

void AircraftCarrier::setWarPlanes(const std::vector<Aircraft> &warPlanes)
{
    _warPlanes = warPlanes;
}

int AircraftCarrier::getAmountOfAmmo() const
{
    return _amountOfAmmo;
}

void AircraftCarrier::setAmountOfAmmo(int amountOfAmmo)
{
    _amountOfAmmo = amountOfAmmo;
}

int AircraftCarrier::getHealthPoint() const
{
    return _healthPoint;
}

void AircraftCarrier::setHealthPoint(int healthPoint)
{
    _healthPoint = healthPoint;
}

void AircraftCarrier::add(Aircraft *aircraft)
{
    _warPlanes.push_back(*aircraft);
}

void AircraftCarrier::fill()
{
    
}

std::string AircraftCarrier::status()
{
    return std::__cxx11::string();
}

