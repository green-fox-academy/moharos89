#include <iostream>

int main(int argc, char *args[]) {

    std::cout << "I want two number!" << std::endl;
    int number1;
    int number2;
    std::cin >> number1;
    std::cin >> number2;

    if (number1 > number2) {
        std::cout << "The bigger number is: " << number1 << std::endl;
    } else {
        std::cout << "The bigger number is: " << number2 << std::endl;
    };
    // Write a program that asks for two numbers and prints the bigger one

    return 0;
}