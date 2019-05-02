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

int AnimalShelter::rescue(Animal *animal)
{
    _animals.push_back(animal);
    return _animals.size();
}

int AnimalShelter::heal()
{
    for (int i = 0; i < _animals.size(); ++i) {
        if (!_animals[i]->isIsHealthy() && _budget >= _animals[i]->getHealCost()) {
            setBudget(getBudget() - _animals[i]->getHealCost());
            _animals[i]->setIsHealthy(true);
            return 1;
        }
    }
    return 0;
}

void AnimalShelter::addAdopter(std::string name)
{
    _adopters.push_back(name);

}

void AnimalShelter::findNewOwner()
{

}

int AnimalShelter::earnDonation(int amount)
{
    int newBudget = _budget + amount;
    setBudget(newBudget);
    return getBudget();
}

void AnimalShelter::toString()
{
    std::cout << "Budget: " << getBudget() << "E,\n" << "There are " << _animals.size() << " animal(s) and "
              << _adopters.size() << " potentional adopter(s)" << std::endl;
    for (int i = 0; i < _animals.size(); ++i) {
        _animals[i]->toString();
    }

}
