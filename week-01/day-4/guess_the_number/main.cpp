#include <iostream>

int main(int argc, char *args[]) {

    int a = 9;
    int b;
    std::cout << "Give me a number" << std::endl;
    std::cin >> b;
    while (b != a || b == a) {
        if (b != a) {
            while (b != a) {
                if (b < a) {
                    std::cout << "The stored number is higher" << std::endl;
                    std::cin >> b;
                } else {
                    std::cout << "The stored number is lower" << std::endl;
                    std::cin >> b;
                }

            }
        } else {
            std::cout << "You found the number : " << a << std::endl;
            break;
        }
    }
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    return 0;
}