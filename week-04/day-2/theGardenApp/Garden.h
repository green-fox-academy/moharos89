//
// Created by Bence on 2019.04.23..
//
#include "Flower.h"
#include "Tree.h"
#ifndef THEGARDENAPP_GARDEN_H
#define THEGARDENAPP_GARDEN_H


class Garden {
public:
    Garden(std::string name);
    void addPlant(Plant &);
    void watering(double water);
    void setName(std::string name);
    void getGardenStatus();



private:
    std::string _name;
    std::vector<Plant*> _plants;

};


#endif //THEGARDENAPP_GARDEN_H
