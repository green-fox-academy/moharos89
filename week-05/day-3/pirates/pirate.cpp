//
// Created by Bence on 2019.05.01..
//

#include "pirate.h"



Pirate::Pirate() {
    setName("Expendable");
    setToxicLevel(0);

}

Pirate::Pirate(std::string name) {
    setName(name);
    setToxicLevel(0);


}

void Pirate::setToxicLevel(int toxicLevel) {
    _toxicLevel = toxicLevel;
}

void Pirate::setName(const std::string &name) {
    _name = name;
}

int Pirate::getToxicLevel() const {
    return _toxicLevel;
}

const std::string &Pirate::getName() const {
    return _name;
}


void Pirate::drinkSomeRum() {
    _toxicLevel += 1;

}

void Pirate::howItGoingMate() {
    if (!heIsDead() && !_passedOut) {
        int toxic = getToxicLevel();
        if (toxic <= 3) {
            drinkSomeRum();
            std::cout << "Pour me anudder!" << std::endl;
        } else {
            drinkSomeRum();
            int chance = 0;
            chance = rand() % 100 + 1;
            std::cout << chance << std::endl;
            if (chance >= 60 && chance <= 65) {
                die();
            } else {
                passesOut();
                std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
            }
        }
    } else if(!heIsDead() && _passedOut) {
        sleepOff();
    }
}

void Pirate::passesOut() {
    if (_toxicLevel == 0) {
        _passedOut = false;
    } else {
        _passedOut = true;
    }
}

void Pirate::sleepOff() {
    int toxic = _toxicLevel;
    toxic -= 1;
    setToxicLevel(toxic);
    std::cout << "Sleeping" << std::endl;
    if (_toxicLevel == 0) {
        passesOut();
        std::cout << "I'm here mates!" << std::endl;
    }

}

bool Pirate::heIsDead() {
    if (_live == false) {
        std::cout << "He is dead" << std::endl;
        return true;
    } else {
        return false;
    }
}

void Pirate::brawl(Pirate *pirate) {
    int chance = rand() % 3 + 1;
    if (chance == 1) {
        die();
    } else if (chance == 2) {
        pirate->die();
    } else {
        passesOut();
        pirate->passesOut();
        std::cout << "They are in a dream world!" << std::endl;
    }
}

void Pirate::die() {
    _live = false;
    std::cout << _name << " died!" << std::endl;
}


