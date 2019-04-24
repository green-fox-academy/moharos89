//
// Created by Bence on 2019.04.24..
//

#include "bassGuitar.h"

void BassGuitar::play() {
    std::cout << _name << ", a " << printNumberOfStrings() << " instrument that goes " << sound() << std::endl;

}

std::string BassGuitar::sound() {
    return _sound;
}

BassGuitar::BassGuitar() {
    setNumberOfStrings(4);
    setName("Bass Guitar");
    setSound("Duum-duum-duum");

}

BassGuitar::BassGuitar(int numberOfStrings) : StringedInstrument(numberOfStrings) {
    setName("Bass Guitar");
    setSound("Duum-duum-duum");
}

void BassGuitar::setName(std::string name) {
    _name = name;

}

const std::string BassGuitar::getName() const {
    return _name;
}

void BassGuitar::setSound(std::string sound) {
    _sound = sound;

}
