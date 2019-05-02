//
// Created by Bence on 2019.05.02..
//

#include "f35.h"

std::string F35::getType()
{
    return "F35";
}

std::string F35::getStatus()
{
    std::string status =
            "Type: " + getType() + ", Ammo: " + std::to_string(getAmmo()) + ", Base Damage: 50, All Damage: " +
            std::to_string(getAmmo() * getBaseDamage());
    return status;
}

bool F35::isPriority()
{
    return true;
}
