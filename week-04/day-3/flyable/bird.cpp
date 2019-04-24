//
// Created by Bence on 2019.04.24..
//

#include "bird.h"

Bird::Bird() {
    setName("Bird");

}

Bird::Bird(std::string name) {
    setName(name);

}

std::string Bird::breed() {
    return "laying eggs.";
}

const std::string Bird::getName() const {
    return _name;
}

void Bird::land() {
    std::cout << "Puff Paff, I'm on my feet" << std::endl;

}

void Bird::fly() {
    std::cout << "I'm flying" << std::endl;

}

void Bird::takeOff() {
    std::cout << "Watch your hat I'm going to fly" << std::endl;
}
