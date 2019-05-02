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

    int getAmmo() const;

    void setAmmo(int ammo);

    int getAmmomax() const;

    void setAmmomax(int ammomax);

    int getBaseDamage() const;

    void setBaseDamage(int baseDamage);

    int fight();

    int refill(int ammo);

    virtual std::string getType() = 0;

    virtual std::string getStatus() = 0;

    virtual bool isPriority() = 0;

private:
    int _ammo;


private:
    int _ammomax;
    int _baseDamage;


};


#endif //AIRCRAFT_AIRCRAFT_H
