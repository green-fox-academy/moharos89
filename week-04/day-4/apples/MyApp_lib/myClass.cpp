//
// Created by Bence on 2019.04.24..
//

#include "myClass.h"

std::string myClass::getApple() {
    return "apple";
}

int myClass::sum(std::vector<int> *numbers) {
    int value = 0;
    for( int i = 0; i < numbers->size(); i++) {
        value += numbers->at(i);
    }
    return value;
}
