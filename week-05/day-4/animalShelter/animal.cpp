//
// Created by Bence on 2019.05.02..
//

#include "animal.h"

Animal::Animal()
{
 setIsHealthy(false);
}

Animal::Animal(std::string name)
{
    setName(name);
    setIsHealthy(false);
}

Animal::Animal(std::string name, bool isHealthy)
{
    setName(name);
    setIsHealthy(isHealthy);

}

const std::string &Animal::getName() const
{
    return _name;
}

void Animal::setName(const std::string &name)
{
    _name = name;
}

bool Animal::isIsHealthy() const
{
    return _isHealthy;
}

void Animal::setIsHealthy(bool isHealthy)
{
    _isHealthy = isHealthy;
}

int Animal::getHealCost() const
{
    return _healCost;
}

void Animal::setHealCost(int healCost)
{
    Animal::_healCost = healCost;
}

bool Animal::isAdoptable()
{
    if(isIsHealthy()) {
        return true;
    } else {
        return false;
    }
}

void Animal::toString()
{
    if(_isHealthy) {
        std::cout << _name << " is healthy, and adoptable" << std::endl;
    } else {
        std::cout << _name << " is not healthy (" << std::to_string(_healCost) << "), and not adoptable" << std::endl;
    }
}

