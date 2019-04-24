//
// Created by Bence on 2019.04.24..
//

#ifndef ZOO_REPTILE_H
#define ZOO_REPTILE_H


#include "animal.h"

class Reptile : public Animal {
public:
    Reptile();
    Reptile(std::string name);
    std::string breed() override ;
    const std::string getName() const override ;






private:

    int _scaleSize;
    int _scaleColor;




};


#endif //ZOO_REPTILE_H
