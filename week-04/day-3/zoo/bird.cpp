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
