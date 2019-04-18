#include <iostream>
#include "Station.h"

int main() {

    Station Shell(1200);
    Car Ford(25 , 30);
    Car Suzuki(23 , 25);
    Car Renault(196 , 200);
    Car Tesla(0 , 0);
    Car Mustang(65 , 70);
    Shell.fill(Ford);
    Shell.fill(Suzuki);
    Shell.fill(Tesla);
    Shell.fill(Renault);
    Shell.fill(Mustang);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}