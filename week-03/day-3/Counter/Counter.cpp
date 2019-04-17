//
// Created by Bence on 2019.04.17..
//

#include "Counter.h"

Counter::Counter() {
    setNumber(0);
    setNumberbackup(0);

}

Counter::Counter(int number) {
    setNumber(number);
    setNumberbackup(number);

}

void Counter::setNumber(int number) {
    _number = number;

}

void Counter::setNumberbackup(int numberbackup) {
    _numberbackup = numberbackup;
}

int Counter::get() {
    return _number;
}

int Counter::getNumberbackup() {
    return _numberbackup;
}

void Counter::add(int number) {
    _number += number;

}

void Counter::add() {
    _number += 1;
}

void Counter::reset() {
    _number = _numberbackup;

}
