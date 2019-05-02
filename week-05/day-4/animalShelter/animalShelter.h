//
// Created by Bence on 2019.05.02..
//

#ifndef ANIMALSHELTER_ANIMALSHELTER_H
#define ANIMALSHELTER_ANIMALSHELTER_H

#include "animal.h"
#include <vector>

class AnimalShelter {
public:
    AnimalShelter();

    int getBudget() const;

    void setBudget(int budget);

    const std::vector<Animal *> &getAnimals() const;

    void setAnimals(const std::vector<Animal *> &animals);

    const std::vector<std::string> &getAdopters() const;

    void setAdopters(const std::vector<std::string> &adopters);

    int rescue(Animal *animal);

    int heal();

    void addAdopter(std::string name);

    void findNewOwner();

    int earnDonation(int amount);

    void toString();


private:
    int _budget;
    std::vector<Animal *> _animals;
    std::vector<std::string> _adopters;
};


#endif //ANIMALSHELTER_ANIMALSHELTER_H
