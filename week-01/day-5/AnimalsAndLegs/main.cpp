#include <iostream>

int main(int argc, char* args[]) {

    int a , b;
    std::cout << "How many chickens does the farmer has?" << std::endl;
    std::cin >> a;
    std::cout << "How many pigs does the farmer has?" << std::endl;
    std::cin >> b;

    int AnimalsLegs = a * 2 + b * 4;
    std::cout << "Animals legs: " << AnimalsLegs << std::endl;
    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    return 0;
}