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

const std::string Sharpie::getColor() const {
    return _color;
}

float Sharpie::getWidth() {
    return _width;
}

const float Sharpie::getInkAmount() const {
    return _inkAmount;
}

void Sharpie::use() {

    std::cout << write() << std::endl;
    _inkAmount -= 20;

}

std::string Sharpie::write() {
    std::cout << "Write something!" << std::endl;
    std::string temp;
    std::cin >> temp;
    return temp;
}
