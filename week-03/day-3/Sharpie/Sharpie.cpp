//
// Created by Bence on 2019.04.17..
//

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width) {
    setColor(color);
    setWidth(width);
    setInkAmount(100);
}

void Sharpie::setColor(std::string color) {
    _color = color;

}

void Sharpie::setWidth(float width) {
    _width = width;

}

void Sharpie::setInkAmount(float inkAmount) {
    _inkAmount = inkAmount;
}

std::string Sharpie::getColor() {
    return _color;
}

float Sharpie::getWidth() {
    return _width;
}

float Sharpie::getInkAmount() {
    return _inkAmount;
}

void Sharpie::use() {
    _inkAmount -= 1;

}
