//
// Created by Bence on 2019.05.02..
//

#ifndef ANIMALSHELTER_CAT_H
#define ANIMALSHELTER_CAT_H


#include "animal.h"

class Cat : public Animal {
public:
    Cat();

    Cat(const std::string &name);

    Cat(std::string name , bool isHealthy);

private:
};


#endif //ANIMALSHELTER_CAT_H
