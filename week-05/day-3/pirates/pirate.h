//
// Created by Bence on 2019.05.01..
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <time.h>

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H


class Pirate {
public:
    Pirate();

    Pirate(std::string name);

    void setToxicLevel(int toxicLevel);

    void setName(const std::string &name);

    int getToxicLevel() const;

    const std::string &getName() const;

    void drinkSomeRum();

    void howItGoingMate();

    void passesOut();

    void sleepOff();

    bool heIsDead();

    void brawl(Pirate *pirate);

    void die();


private:
    int _toxicLevel;
    std::string _name;
    bool _live = true;
    bool _passedOut = false;


};


#endif //PIRATES_PIRATE_H
