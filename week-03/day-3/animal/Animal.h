//
// Created by Bence on 2019.04.17..
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal {
public:
    Animal();

    void setHunger(int meat);

    void setThirst(int fluid);

    int getHunger();

    int getThirst();

    void eat();

    void drink();

    void play();

private:
    int _hunger;
    int _thirst;


};


#endif //ANIMAL_ANIMAL_H
