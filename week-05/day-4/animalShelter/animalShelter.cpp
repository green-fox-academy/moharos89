//
// Created by Bence on 2019.05.02..
//

#include "animalShelter.h"

AnimalShelter::AnimalShelter()
{
    setBudget(50);
}

int AnimalShelter::getBudget() const
{
    return _budget;
}

void AnimalShelter::setBudget(int budget)
{
    _budget = budget;
}

const std::vector<Animal *> &AnimalShelter::getAnimals() const
{
    return _animals;
}

void AnimalShelter::setAnimals(const std::vector<Animal *> &animals)
{
    _animals = animals;
}

const std::vector<std::string> &AnimalShelter::getAdopters() const
{
    return _adopters;
}

void AnimalShelter::setAdopters(const std::vector<std::string> &adopters)
{
    _adopters = adopters;
}
