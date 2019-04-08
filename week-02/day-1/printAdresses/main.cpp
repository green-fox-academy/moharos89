
#include <iostream>

int main() {
    int numbers[5];
    for (int i = 0; i < 5; i++) {

        std::cout << "Give me a number!" << std::endl;
        std::cin >> numbers[i];
    }
    for (int j = 0; j < 5; j++) {
        int *numptr = &numbers[j];
        std::cout << numptr << std::endl;
    }


    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    return 0;
}