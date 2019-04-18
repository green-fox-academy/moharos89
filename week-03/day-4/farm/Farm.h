//
// Created by Bence on 2019.04.18..
//

#ifndef FARM_FARM_H
#define FARM_FARM_H

#include "Animal.h"

class Farm {
public:
    Farm(int slots);
    void setAnimal(Animal animal);
    void setSlot(int slot);
    const std::string getAnimals() const;
    const int getSlot ();
    const int getfreeSlot ();
    void breed();
    void slaughter();


private:
    std::vector<Animal> _animalList;
    int _slot;

};


#endif //FARM_FARM_H
