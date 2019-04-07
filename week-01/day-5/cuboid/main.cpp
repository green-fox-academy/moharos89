#include <iostream>

int main(int argc, char *args[]) {

    std::cout << "Write down the parameters of your cuboid" << std::endl;
    int a, b, c;
    std::cin >> a >> b >> c;

    int surface = 2 * (a * b + a * c + b * c);
    int volume = a * b * c;
    std::cout << "Surface Area: " << surface << "\n" << "Volume: " << volume << std::endl;

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    return 0;
}