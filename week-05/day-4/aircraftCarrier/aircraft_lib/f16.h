//
// Created by Bence on 2019.05.02..
//

#ifndef AIRCRAFT_F16_H
#define AIRCRAFT_F16_H


#include "aircraft.h"

class F16 : public Aircraft{
public:
    F16();

    int fight() override;

    int refill(int ammo) override;

    int getAmmo() const;

    void setAmmo(int ammo);

    void getType() override;

    void getStatus() override;

    bool isPriority() override;

private:
    int _ammo;

};


#endif //AIRCRAFT_F16_H
