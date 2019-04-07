#include <iostream>

int main(int argc, char *args[]) {
    std::cout << "I want a number" << std::endl;
    int a;
    std::cin >> a;
    for (int i = 0; i < a; i++)
        if (i == 0 | (i == a - 1)) {
            for (int j = 0; j < a; j++) {
                if (j < a - 1) {
                    std::cout << "%";
                } else {
                    std::cout << "%" << std::endl;
                }
            }
        } else {
            for (int j = 0; j < a; j++) {
                if (j == 0) {
                    std::cout << "%";
                }else if (j == (a - 1)){
                    std::cout << "%" << std::endl;
                } else {
                    std::cout << " ";
                }
            }
        }
    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%%
    // %    %
    // %    %
    // %    %
    // %    %
    // %%%%%%
    //
    // The square should have as many lines as the number was

    return 0;
}