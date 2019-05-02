//
// Created by Bence on 2019.05.02..
//

#ifndef AIRCRAFT_AIRCRAFT_H
#define AIRCRAFT_AIRCRAFT_H

#include <iostream>
#include <string>

class Aircraft {
public:
    Aircraft();
    virtual int fight() = 0;
    virtual int refill(int ammo) = 0;
    virtual std::string getType() = 0;
    virtual std::string getStatus() = 0;
    virtual bool isPriority() = 0;

private:


};


#endif //AIRCRAFT_AIRCRAFT_H
