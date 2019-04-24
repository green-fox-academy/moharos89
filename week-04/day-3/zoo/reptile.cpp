//
// Created by Bence on 2019.04.24..
//

#include "reptile.h"

Reptile::Reptile() {
    setName("Reptile");

}

Reptile::Reptile(std::string name) {
    setName(name);

}

std::string Reptile::breed() {
    return "laying eggs.";

}

const std::string Reptile::getName() const {
    return _name;
}
