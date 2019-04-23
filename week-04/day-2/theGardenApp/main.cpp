#include <iostream>
#include "Flower.h"
#include "Tree.h"
#include "Garden.h"
int main() {

    Flower flower1("yellow" , 0);
    Flower flower2("blue" , 0);
    Tree tree1("purple" , 0);
    Tree tree2("orange" , 0);
    Garden garden("Spring");
    garden.addPlant(flower1);
    garden.addPlant(flower2);
    garden.addPlant(tree1);
    garden.addPlant(tree2);
    garden.getGardenStatus();
    garden.watering(40);
    garden.watering(70);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}