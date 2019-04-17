//
// Created by Bence on 2019.04.17..
//

#include "Animal.h"

Animal::Animal() {
    setHunger(50);
    setThirst(50);
}
void Animal::setHunger(int meat) {
    _hunger = meat;
}
void Animal::setThirst(int fluid) {
    _thirst = fluid;
}
int Animal::getHunger() {
    return _hunger;
}
int Animal::getThirst() {
    return _thirst;
}

void Animal::eat() {
    _hunger -= 1;

}

void Animal::drink() {
    _thirst -= 1;

}

void Animal::play() {
    _hunger += 1;
    _thirst += 1;

}
