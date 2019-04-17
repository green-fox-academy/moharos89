//
// Created by Bence on 2019.04.17..
//
#include <string>
#include <iostream>
#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie {
public:
    Sharpie (std::string color , float width);
    void setColor(std::string color);
    void setWidth(float width);
    void setInkAmount(float inkAmount);
    std::string getColor();
    float getWidth();
    float getInkAmount();
    void use();

private:
    std::string _color;
    float _width;
    float _inkAmount;

};


#endif //SHARPIE_SHARPIE_H
