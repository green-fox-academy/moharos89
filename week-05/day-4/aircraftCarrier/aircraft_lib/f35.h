//
// Created by Bence on 2019.05.02..
//

#ifndef AIRCRAFT_F35_H
#define AIRCRAFT_F35_H


#include "aircraft.h"

class F35 : public Aircraft {
    F35();

public:
    std::string getType() override;

    std::string getStatus() override;

    bool isPriority() override;

};


#endif //AIRCRAFT_F35_H
