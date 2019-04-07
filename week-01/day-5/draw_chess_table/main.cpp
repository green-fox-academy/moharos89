#include <iostream>

int main(int argc, char *args[]) {
    int a = 8;
    for (int i = 0; i < a; i++) {
        if ((i % 2) == 0) {
            for (int j = 0; j < a; j++) {
                if ((j % 2) == 0) {
                    std::cout << "%";
                } else if (j == (a - 1)) {
                    std::cout << " " << std::endl;
                } else {
                    std::cout << " ";
                }

            }
        } else {
            for (int k = 0; k < a; k++) {
                if ((k % 2) == 0) {
                    std::cout << " ";
                } else if (k == (a - 1)) {
                    std::cout << "%" << std::endl;
                } else {
                    std::cout << "%";

                }
            }
        }
    }

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    return 0;
}