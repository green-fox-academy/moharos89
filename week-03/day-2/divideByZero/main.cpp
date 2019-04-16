#include <iostream>
#include <fstream>
void divider (int);

int main() {
    std::cout << "Write a number!" << std::endl;
    int a;
    std::cin >> a;
    divider(a);

    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    return 0;
}
void divider (int a){

    try {
        if (a == 0) {
            throw std::string("Fail");
        } else {
            std::cout << 10 / a << std::endl;
        }
    } catch (std::string& e) {
        std::cout << e << std::endl;
    }

}

