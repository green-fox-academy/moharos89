#include <iostream>

int main(int argc, char *args[]) {

    std::cout << "I want a number!" << std::endl;
    int a;
    std::cin >> a;
    if (a % 2 == 1) {
        for (int i = 0; i < a; i++) {
            int b = a / 2 + 1;
            if (i < b) {
                for (int j = 0; j <= a; j++) {
                    if ((j == b) | (j >= (b - i) && j < b) | ((j <= (b + i)) && (j > b) && (j != a))) {
                        std::cout << "*";
                    } else if (j == a && i == b - 1) {
                        std::cout << "*" << std::endl;
                    } else if (j == a) {
                        std::cout << std::endl;
                    } else {
                        std::cout << " ";
                    }
                }
            } else {
                for (int k = 0; k <= a; k++) {
                    int c = a / 2;
                    if ((k == b) | (k >= (i - c + 1) && k < b) | ((k <= a - (i - c)) && (k > b) && (k != a))) {
                        std::cout << "*";
                    } else if (k == a && i == a) {
                        std::cout << " " << std::endl;
                    } else if (k == a) {
                        std::cout << std::endl;
                    } else {
                        std::cout << " ";
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < a; i++) {
            int b = a / 2;
            if (i < b) {
                for (int j = 0; j < a; j++) {
                    if ((j >= (b - 1 - i) && j < b) | ((j <= (b + i)) && (j >= b) && (j != a - 1))) {
                        std::cout << "*";
                    } else if (j == a - 1 && i == b - 1) {
                        std::cout << "*" << std::endl;
                    } else if (j == a - 1) {
                        std::cout << std::endl;
                    } else {
                        std::cout << " ";
                    }
                }

            } else {
                for (int k = 0; k <= a; k++) {
                    int c = a / 2;
                    if ((k == b) | (k >= (i - c) && k < b) | ((k < a - (i - c)) && (k > b) && (k != a))) {
                        std::cout << "*";
                    } else if (k == a && i == a) {
                        std::cout << " " << std::endl;
                    } else if (k == a) {
                        std::cout << std::endl;
                    } else {
                        std::cout << " ";
                    }
                }
            }
        }

    }


// Write a program that reads a number from the standard input, then draws a
// diamond like this:
//
//
//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *
//
// The diamond should have as many lines as the number was

    return 0;
}