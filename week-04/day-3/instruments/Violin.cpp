//
// Created by Bence on 2019.04.24..
//

#include "Violin.h"

Violin::Violin() {
    setNumberOfStrings(4);
    setName("Violin");
    setSound("Screech");

}

Violin::Violin(int numberOfStrings) : StringedInstrument(numberOfStrings) {
    setName("Violin");
    setSound("Screech");
}

void Violin::setName(std::string name) {
    _name = name;

}

const std::string Violin::getName() const {
    return _name;
}

void Violin::setSound(std::string sound) {
    _sound = sound;

}

void Violin::play() {
    std::cout << _name << ", a " << printNumberOfStrings() << " instrument that goes " << sound() << std::endl;


}

std::string Violin::sound() {
    return _sound;
}
