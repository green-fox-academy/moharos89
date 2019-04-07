#include <iostream>

int main(int argc, char *args[]) {
    std::cout << "Give me 5 number" << std::endl;
    int a, b, c, d, e;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;
    int sum = a + b + c + d + e;
    double avar = sum / 5.0;
    std::cout << "Sum: " << sum << "," << "Avarage: " << avar << std::endl;
    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4

    return 0;
}