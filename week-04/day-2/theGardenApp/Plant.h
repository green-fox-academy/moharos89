//
// Created by Bence on 2019.04.23..
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

#ifndef THEGARDENAPP_PLANT_H
#define THEGARDENAPP_PLANT_H


class Plant {
public:
    Plant();
    Plant(std::string color , double waterLevel);
    void setColor (std::string color);
    void setWaterLevel(double waterLevel);
    const std::string getColor() const;
    const double getWaterLevel() const;
    virtual void getSomeWater(double water);
    virtual bool waterLevelIndicator();
    virtual void printWaterNeed(bool waterNeed);

protected:
    std::string _color;
    double _waterLevel;

private:

};


#endif //THEGARDENAPP_PLANT_H
