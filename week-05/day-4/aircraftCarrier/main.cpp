#include <iostream>
#include "aircraftCarrier.h"
#include "f16.h"
#include "f35.h"

int main() {

    AircraftCarrier boat1(3000 , 250);
    F16 plane1;
    F16 plane2;
    F16 plane3;
    F16 plane4;
    F16 plane5;
    F35 plane6;
    F35 plane7;
    F35 plane8;
    F35 plane9;
    F35 plane10;
    boat1.add(&plane1);
    boat1.add(&plane2);
    boat1.add(&plane3);
    boat1.add(&plane4);
    boat1.add(&plane5);
    boat1.add(&plane6);
    boat1.add(&plane7);
    boat1.add(&plane8);
    boat1.add(&plane9);
    boat1.add(&plane10);
    std::cout << boat1.status() << std::endl;
    boat1.fill();
    std::cout << boat1.status() << std::endl;
    AircraftCarrier boat2;
    std::cout << boat2.status() << std::endl;
    boat1.fight(&boat2);
    boat1.fill();
    boat1.fight(&boat2);
    boat1.fill();
    boat1.fight(&boat2);
    std::cout << boat2.status() << std::endl;
    std::cout << boat1.status() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}