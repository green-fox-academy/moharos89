#include <iostream>
#include "Sharpie.h"
#include "SharpieSet.h"

int main() {
    Sharpie blue("blue" , 1.2);
    Sharpie green("green" , 1.5);
    Sharpie yellow("yellow" , 0.5);
    SharpieSet bag;
    bag.addSharpie(blue);
    bag.addSharpie(green);
    bag.addSharpie(yellow);
    bag.use("blue");
    bag.use("blue");
    bag.use("blue");
    bag.use("blue");
    bag.use("blue");
    bag.use("yellow");
    std::cout << bag.countUsable() << std::endl;
    bag.removeTrash();
    bag.getSharpie();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}