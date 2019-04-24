//
// Created by Bence on 2019.04.24..
//

#include "stringedInstrument.h"

StringedInstrument::StringedInstrument() {

}

StringedInstrument::StringedInstrument(int numberOfStrings) {
     setNumberOfStrings(numberOfStrings);

}

void StringedInstrument::setNumberOfStrings(int numberOFStrings) {
    _numberOfStrings = numberOFStrings;

}

const int StringedInstrument::getNumberOFStrings() const {
    return _numberOfStrings;
}

std::string StringedInstrument::printNumberOfStrings() {
    return std::to_string(getNumberOFStrings()) + "-stringed";

}

