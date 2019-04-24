//
// Created by Bence on 2019.04.24..
//

#include "animal.h"

Animal::Animal() {
    setGender(FEMALE);
    setAge(5);
    setHunger(50);
    setThirst(50);


}

void Animal::setName(std::string name) {
    _name = name;
}

void Animal::setAge(int age) {
    _age = age;

}

void Animal::setGender(Gender gender) {
    _gender = gender;

}

void Animal::setHunger(int hunger) {
    _hunger = hunger;
}

void Animal::setThirst(int thirst) {
    _thirst = thirst;

}

void Animal::eat(int amount) {
    _hunger -= amount;

}

void Animal::drink(int amount) {
    _thirst -= amount;
}

const std::string Animal::getGender(Gender gender) const {
    switch (gender) {
        case MALE:
            return "male";
        case FEMALE:
            return "female";

    }
}

const int Animal::getAge() const {
    return _age;
}
