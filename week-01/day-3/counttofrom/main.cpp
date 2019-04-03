#include <iostream>

int main(int argc, char* args[]) {

    int a;
    int b;
    std::cout << "I want two number! I'm hungry pls hurry write them down with one space between them!" << std::endl;
    std::cin >> a >> b;
    if (a > b) {
        std::cout << "The secound number should be bigger" << std::endl;
    } else {
        while (a < b) {
            std::cout << a << std::endl;
            a += 1;
        }
    }





    return 0;
}