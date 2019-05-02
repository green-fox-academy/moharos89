//
// Created by Bence on 2019.05.02..
//

#ifndef ANIMALSHELTER_PARROT_H
#define ANIMALSHELTER_PARROT_H


#include "animal.h"

class Parrot : public Animal {
public:
    Parrot();

    Parrot(const std::string &name);

    Parrot(const std::string &name, bool isHealthy);

private:
};


#endif //ANIMALSHELTER_PARROT_H
