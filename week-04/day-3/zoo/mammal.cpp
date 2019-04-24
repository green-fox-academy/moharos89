//
// Created by Bence on 2019.04.24..
//

#include "mammal.h"

Mammal::Mammal() {
    setName("Mammal");

}

Mammal::Mammal(std::string name) : Animal() {
    setName(name);
}

std::string Mammal::breed() {
    return "pushing miniature versions out.";
}

const std::string Mammal::getName() const {
    return _name;
}

void Mammal::setFur(std::string fur) {
    _fur = fur;

}

void Mammal::setBreast(int breastNumber) {
    _breast = breastNumber;

}

const std::string Mammal::getFur() const {
    return _fur;
}

const int Mammal::getBreast() const {
    return _breast;
}
