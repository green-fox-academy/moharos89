//
// Created by Bence on 2019.05.02..
//

#include "parrot.h"

Parrot::Parrot()
{
    setHealCost(rand() % 7 + 4);
    setName("arrot");
}

Parrot::Parrot(const std::string &name) : Animal(name)
{
    setHealCost(rand() % 7 + 4);

}

Parrot::Parrot(const std::string &name, bool isHealthy) : Animal(name, isHealthy)
{
    setHealCost(rand() % 7 + 4);

}
