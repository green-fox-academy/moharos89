//
// Created by Bence on 2019.04.23..
//

#ifndef THEGARDENAPP_FLOWER_H
#define THEGARDENAPP_FLOWER_H

#include "Plant.h"

class Flower : public Plant {
public:
    Flower(std::string color , double waterLevel);
    void setName();
    const std::string getname();
    void getSomeWater(double water) override;
    void printWaterNeed(bool waterNeed) override;


private:
    std::string _name;

};


#endif //THEGARDENAPP_FLOWER_H
