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
    _warPlanes.push_back(aircraft);
}

void AircraftCarrier::fill()
{
    try {
        if (_amountOfAmmo == 0) {
            throw std::exception();
        }
        int neededAmmo = 0;
        for (int i = 0; i < _warPlanes.size(); ++i) {
            neededAmmo += _warPlanes[i]->getAmmomax() - _warPlanes[i]->getAmmo();
        }
        if (neededAmmo < _amountOfAmmo) {
            for (int l = 0; l < _warPlanes.size(); ++l) {
                if (_warPlanes[l]->isPriority()) {
                    setAmountOfAmmo(_warPlanes[l]->refill(_amountOfAmmo));
                }
            }
            for (int j = 0; j < _warPlanes.size(); ++j) {
                setAmountOfAmmo(_warPlanes[j]->refill(_amountOfAmmo));
            }
        } else {
            for (int k = 0; k < _warPlanes.size(); ++k) {
                setAmountOfAmmo(_warPlanes[k]->refill(_amountOfAmmo));
            }
        }

    } catch (std::exception e) {
        std::cout << "There is no ammo left" << std::endl;
    }
}

std::string AircraftCarrier::status()
{
    std::string status;
    status = "HP: " + std::to_string(getHealthPoint()) + ", Aircraft count: " + std::to_string(_warPlanes.size());
    status + ", Ammo Storage: " + std::to_string(_amountOfAmmo) + ", Total damage ";
    int sum = 0;
    for (int i = 0; i < _warPlanes.size(); ++i) {
        sum += _warPlanes[i]->getAmmo() * _warPlanes[i]->getBaseDamage();
    }
    status + std::to_string(sum) + "\n";
    status + "Aircrafts: \n";
    for (int j = 0; j < _warPlanes.size(); ++j) {
        status + _warPlanes[j]->getStatus() + "\n";
    }
    return status;
}

const std::vector<Aircraft *> &AircraftCarrier::getWarPlanes() const
{
    return _warPlanes;
}

void AircraftCarrier::setWarPlanes(const std::vector<Aircraft *> &warPlanes)
{
    _warPlanes = warPlanes;
}

