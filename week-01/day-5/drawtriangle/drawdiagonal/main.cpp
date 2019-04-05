#include <iostream>

int main(int argc, char *args[]) {

    int a;
    std::cout << " Do you want to draw a diagonal, pleas write down a number!" << std::endl;
    std::cin >> a;
    for (int b = 0; b <= a; b++) {
        if (b == 0 || b == a) {
            for (int t = 0; t < a; t++)
                if (t == (a - 1)) {
                    std::cout << "%" << std::endl;
                } else {
                    std::cout << "%";
                }
        } else {
            for (int c = 0; c < a; c++) {
                if (c == 0) {
                    std::cout << "%";
                } else if (c == b && c != (a-1)) {
                    std::cout << "%";
                } else if (c == (a-1)) {
                    std::cout << "%" << std::endl;
                } else {
                    std::cout << " ";
                }
            }
        }
    }


    return 0;
}