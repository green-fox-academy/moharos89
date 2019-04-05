#include <iostream>

int main(int argc, char *args[]) {

    int a;
    std::cout << " PLs write a number!";
    std::cin >> a;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= (i + 1); j++) {
            if (j <= i) {
                std::cout << "*";
            } else {
                std::cout << std::endl;
            }
        }
    }

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was

    return 0;
}