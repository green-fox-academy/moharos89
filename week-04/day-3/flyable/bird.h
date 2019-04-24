//
// Created by Bence on 2019.04.24..
//

#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H


#include "animal.h"
#include "flyable.h"

class Bird : public Animal , public Flyable{
public:
    Bird();
    Bird(std::string name);
    std::string breed() override ;
    const std::string getName() const override ;

    void land() override;

    void fly() override;

    void takeOff() override;

private:
    int _wingsize;
    int _fatherSize;
    std::string _fatherColor;

};


#endif //ZOO_BIRD_H
