#include <iostream>

int main(int argc, char *args[]) {
    std::cout << "I want a number!" << std::endl;
    int a;
    std::cin >> a;
    int sum = 0;
    double avar = 0.0;
    for (int i = 0; i < a; i++) {
        int number;
        std::cout << " Pls write a number, " << a - (1 * i) << " number remained to complete your part."
                  << std::endl;
        std::cin >> number;
        sum += number;
        avar = (double) sum / a;
        if (i == a - 1) {
            std::cout << "Sum: " << sum << ", " << "Avarage: " << avar << std::endl;
        }

    }


    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4

    return 0;
}