//
// Created by Bence on 2019.05.02..
//

#include "f16.h"

F16::F16() {
    setAmmo(0);

}

int F16::getAmmo() const {
    return _ammo;
}

void F16::setAmmo(int ammo) {
    _ammo = ammo;
}

int F16::fight() {
    int usedAmmo = (0 - _ammo) * (-1);
    setAmmo(0);
    return usedAmmo * 30;
}

int F16::refill(int ammo) {
    if (ammo >= 8) {
        setAmmo(8);
        int newAmmo = ammo - 8;
        return newAmmo;
    } else {
        setAmmo(ammo);
        return 0;
    }

}

std::string F16::getType() {
    return "F16";

}

std::string F16::getStatus() {
    std::string status =
            "Type: " + getType() + ", Ammo: " + std::to_string(_ammo) + ", Base Damage: 30, All Damage: " +
            std::to_string(_ammo * 30);
}

bool F16::isPriority() {
    return false;
}

