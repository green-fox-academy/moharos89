#include <iostream>

int main(int argc, char *args[]) {
    std::cout << "I want a number!" << std::endl;
    int a;
    std::cin >> a;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= (a * 2) - 1; j++) {
            if (((j >= (a - i)) && !(j >= a)) | ((j <= (a + i)) && !(j <= a)) | j == a) {
                std::cout << "*";
            } else if (j == (a * 2) - 1) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }

        }
    }

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    return 0;
}