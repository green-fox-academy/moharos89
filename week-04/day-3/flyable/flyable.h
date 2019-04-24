//
// Created by Bence on 2019.04.24..
//

#ifndef FLYABLE_FLYABLE_H
#define FLYABLE_FLYABLE_H

#include <iostream>
#include <string>


class Flyable {
public:
    virtual void land() = 0;
    virtual void fly() = 0;
    virtual void takeOff() = 0;

protected:

private:

};


#endif //FLYABLE_FLYABLE_H
