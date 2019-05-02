//
// Created by Bence on 2019.05.02..
//

#include "cat.h"

Cat::Cat()
{
    setHealCost(rand() % 7);
    setName("Cat");
}

Cat::Cat(const std::string &name) : Animal(name)
{
    setHealCost(rand() % 7);

}

Cat::Cat(std::string name, bool isHealthy) : Animal(name, isHealthy)
{
    setHealCost(rand() % 7);

}
