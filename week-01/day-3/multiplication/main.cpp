#include <iostream>

int main(int argc, char* args[]) {

    int a;
    std::cout << "Write a number" << std::endl;
    std::cin >> a;
    int b = 0;
    while ((b += 1) <= 10) {
        std::cout << b << " * " << a << " = " << a * b << std::endl;
    }


    return 0;
}