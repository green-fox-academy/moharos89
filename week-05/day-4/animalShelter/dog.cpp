//
// Created by Bence on 2019.05.02..
//

#include "dog.h"

Dog::Dog()
{
    setName("Dog");
    setHealCost(rand() % 8 + 1);
}

Dog::Dog(const std::string &name) : Animal(name)
{
    setHealCost(rand() % 8 + 1);
}

Dog::Dog(const std::string &name, bool isHealthy) : Animal(name, isHealthy)
{
    setHealCost(rand() % 8 + 1);
}
