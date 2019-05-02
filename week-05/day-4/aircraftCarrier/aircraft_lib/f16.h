//
// Created by Bence on 2019.05.02..
//

#ifndef AIRCRAFT_F16_H
#define AIRCRAFT_F16_H


#include "aircraft.h"

class F16 : public Aircraft{
public:
    F16();

    std::string getType() override;

    std::string getStatus() override;

    bool isPriority() override;

private:

};


#endif //AIRCRAFT_F16_H
