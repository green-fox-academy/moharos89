#include <iostream>
#include "Animal.h"


int main() {

    Animal Zebra;
    Zebra.play();
    Zebra.play();
    Zebra.play();
    Zebra.play();
    Zebra.play();
    Zebra.play();
    Zebra.play();
    Zebra.drink();
    Zebra.eat();
    Zebra.eat();
    Zebra.setHunger(30);

    std::cout << Zebra.getHunger() << " " << Zebra.getThirst() << std::endl;
    return 0;
}