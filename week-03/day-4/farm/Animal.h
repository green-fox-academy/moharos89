//
// Created by Bence on 2019.04.17..
//
#include <iostream>
#include <vector>

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal {
public:
    Animal();

    void setHunger(int meat);

    void setThirst(int fluid);

    const int getHunger() const ;

    const int getThirst() const;

    void eat();

    void drink();

    void play();

private:
    int _hunger;
    int _thirst;


};


#endif //ANIMAL_ANIMAL_H
