//
// Created by Bence on 2019.05.02..
//

#ifndef ANIMALSHELTER_ANIMAL_H
#define ANIMALSHELTER_ANIMAL_H

#include <string>
#include <iostream>
#include <time.h>

class Animal {
public:
    Animal();

    Animal(std::string name);

    Animal(std::string name , bool isHealthy);

    const std::string &getName() const;

    void setName(const std::string &name);

    bool isIsHealthy() const;

    void setIsHealthy(bool isHealthy);

    int getHealCost() const;

    void setHealCost(int healCost);

    bool isAdoptable();

    void toString();



private:
    std::string _name;
    bool _isHealthy;
    int _healCost;


};


#endif //ANIMALSHELTER_ANIMAL_H
