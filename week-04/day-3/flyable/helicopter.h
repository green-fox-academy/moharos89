//
// Created by Bence on 2019.04.24..
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H


#include "vehicle.h"
#include "flyable.h"

class helicopter : public Vehicle, public Flyable {
public:
    void land() override;

    void fly() override;

    void takeOff() override;

private:

};


#endif //FLYABLE_HELICOPTER_H
