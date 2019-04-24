//
// Created by Bence on 2019.04.24..
//

#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H


#include "animal.h"

class Mammal : public Animal {
public:
    Mammal();
    Mammal(std::string name);
    std::string breed() override ;
    const std::string getName() const override ;
    void setFur(std::string fur);
    void setBreast(int breastNumber);
    const std::string getFur() const;
    const int getBreast() const;



private:
    std::string _fur;
    int _breast;


};


#endif //ZOO_MAMMAL_H
