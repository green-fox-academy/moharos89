#include <iostream>
#include <string>

int main(int argc, char* args[]) {
std::string name;
    std::cout << "What's your name?" << std::endl;
    std::cin >> name;
    std::cout << "Hello " << name  << std::endl << std::endl;

    int a;
    std::cout << "What is your distance from your home to your workplace in kilometers?" << std::endl;
    std::cin >> a;
    std::cout << "In maters is it: " << a * 1000 << std::endl;

    return 0;
}