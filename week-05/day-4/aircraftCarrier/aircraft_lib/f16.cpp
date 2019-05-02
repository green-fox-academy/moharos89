//
// Created by Bence on 2019.05.02..
//

#include "f16.h"


F16::F16()
{
    setAmmomax(8);
    setBaseDamage(30);

}

std::string F16::getType()
{
    return "F16";

}

std::string F16::getStatus()
{
    std::string status =
            "Type: " + getType() + ", Ammo: " + std::to_string(getAmmo()) + ", Base Damage: 30, All Damage: " +
            std::to_string(getAmmo() * getBaseDamage());
    return status;
}

bool F16::isPriority()
{
    return false;
}
