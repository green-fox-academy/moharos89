
#include <iostream>

#include "Fleet.h"


int main(int argc, char* args[])
{
    Fleet fleet;
    Thing o1 ("Get milk");
    Thing o2 ("Remove the obstacles");
    Thing o3 ("Stand up");
    o3.complete();
    Thing o4 ("Eat lunch");
    o4.complete();
    fleet.add(o1);
    fleet.add(o2);
    fleet.add(o3);
    fleet.add(o4);

    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    std::cout << fleet.toString() << std::endl;
    return 0;
}