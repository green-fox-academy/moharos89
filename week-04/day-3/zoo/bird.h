//
// Created by Bence on 2019.04.24..
//

#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H


#include "animal.h"

class Bird : public Animal {
public:
    Bird();
    Bird(std::string name);
    std::string breed() override ;
    const std::string getName() const override ;

private:
    int _wingsize;
    int _fatherSize;
    std::string _fatherColor;

};


#endif //ZOO_BIRD_H
