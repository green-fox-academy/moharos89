//
// Created by Bence on 2019.04.23..
//
#include "Plant.h"
#ifndef THEGARDENAPP_TREE_H
#define THEGARDENAPP_TREE_H


class Tree : public Plant {
public:
    Tree(std::string color , double waterLevel);
    void setName();
    const std::string getName() const;
    void getSomeWater(double water) override;
    bool waterLevelIndicator() override;
    void printWaterNeed(bool waterNeed) override;



private:
    std::string _name;


};


#endif //THEGARDENAPP_TREE_H
