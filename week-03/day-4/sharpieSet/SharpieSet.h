//
// Created by Bence on 2019.04.18..
//
#include <iostream>
#include <vector>

#ifndef SHARPIESET_SHARPIESET_H
#define SHARPIESET_SHARPIESET_H

#include "Sharpie.h"

class SharpieSet {
public:
    SharpieSet();
    void addSharpie(Sharpie &sharpie);
    const int countUsable() const;
    void removeTrash();
    const void getSharpie() const;
    void use(std::string color);



private:
    std::vector<Sharpie> _sharpies;

};


#endif //SHARPIESET_SHARPIESET_H
