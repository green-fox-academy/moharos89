//
// Created by Bence on 2019.05.02..
//

#include "aircraft.h"

Aircraft::Aircraft() {
    setAmmo(0);

}

int Aircraft::getAmmo() const
{
    return _ammo;
}

void Aircraft::setAmmo(int ammo)
{
    _ammo = ammo;
}

int Aircraft::getAmmomax() const
{
    return _ammomax;
}

void Aircraft::setAmmomax(int ammomax)
{
    _ammomax = ammomax;
}

int Aircraft::getBaseDamage() const
{
    return _baseDamage;
}

void Aircraft::setBaseDamage(int baseDamage)
{
    _baseDamage = baseDamage;
}

int Aircraft::fight()
{
    int shot = (0 - _ammo) * (- 1);
    setAmmo(0);
    return shot * _baseDamage;
}

int Aircraft::refill(int ammo)
{
    if(ammo >= _ammomax) {
        setAmmo(_ammomax);
        return ammo - _ammomax;
    } else {
        setAmmo(ammo);
        return 0;
    }

}
