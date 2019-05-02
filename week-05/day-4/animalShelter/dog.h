//
// Created by Bence on 2019.05.02..
//

#ifndef ANIMALSHELTER_DOG_H
#define ANIMALSHELTER_DOG_H


#include "animal.h"

class Dog : public Animal {
public:
    Dog();

    Dog(const std::string &name);

    Dog(const std::string &name, bool isHealthy);
};


#endif //ANIMALSHELTER_DOG_H
