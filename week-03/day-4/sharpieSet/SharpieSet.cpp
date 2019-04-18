//
// Created by Bence on 2019.04.18..
//

#include "SharpieSet.h"

SharpieSet::SharpieSet() {

}

void SharpieSet::addSharpie(Sharpie &sharpie) {
    _sharpies.push_back(sharpie);
}

const int SharpieSet::countUsable() const {
    int counter = 0;
    for (int i = 0; i < _sharpies.size(); i++) {
        if(_sharpies[i].getInkAmount() != 0) {
            counter++;
        }
    }
    return counter;
}

void SharpieSet::removeTrash() {
    std::vector<Sharpie>::iterator SharpieIt = _sharpies.begin();
    for (int i = 0; i < _sharpies.size(); ++i) {
        if(_sharpies[i].getInkAmount() == 0) {
            _sharpies.erase(SharpieIt + i);
        }
    }
}

const void SharpieSet::getSharpie() const {
    for (int i = 0; i < _sharpies.size(); ++i) {
        std::cout << _sharpies[i].getColor() << " " << _sharpies[i].getInkAmount() << std::endl;
    }

}

void SharpieSet::use(std::string color) {
    for (int i = 0; i < _sharpies.size(); ++i) {
        if(_sharpies[i].getColor().compare(color) == 0) {
            _sharpies[i].use();

        }
    }

}

