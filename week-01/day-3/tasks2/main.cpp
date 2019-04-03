#include <iostream>

int main(int argc, char const *argv[]) {

    std::cout << "Hello, World!" << std::endl;
    std::string myname = "Bence Moharos";
    int myage = 29;
    float myheight = 1.71;

    std::cout << myname << std::endl << myage << std::endl << myheight << std::endl << std::endl;

    int a = 22;
    int b = 13;

    std::cout << b + a << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << (float) a / b << std::endl;
    std::cout << a / b << std::endl;
    std::cout << a % b << std::endl << std::endl;

    int c = 6;
    int d = 17;
    int e = 7;
    std::cout << "Coding hours in the semester: " << c * d * e - 2 << std::endl;
    float f = 52;
    std::cout << "percentage of the coding hours: " << f / (((float) d / e) * c * (e - 2)) * 100 << "%" << std::endl;


    return 0;

}
