//
// Created by Bence on 2019.04.24..
//

#include "electricGuitar.h"

void ElectricGuitar::play() {
    std::cout << _name << ", a " << printNumberOfStrings() << " instrument that goes " << sound() << std::endl;

}

void ElectricGuitar::setSound(std::string sound) {
    _sound = sound;
}

ElectricGuitar::ElectricGuitar() {
    setNumberOfStrings(6);
    setName("Electric Guitar");
    setSound("Twang");

}

ElectricGuitar::ElectricGuitar(int numberOfStrings) : StringedInstrument(numberOfStrings) {
    setName("Electric Guitar");
    setSound("Twang");

}

void ElectricGuitar::setName(std::string name) {
    _name = name;

}

std::string ElectricGuitar::sound() {
    return _sound;
}
