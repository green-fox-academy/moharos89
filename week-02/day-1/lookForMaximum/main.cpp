#include <iostream>

void fillarray(int [], int);

int *maxValuePtr(int [], int);

int main() {
    std::cout << "Give me a number" << std::endl;
    int a;
    std::cin >> a;
    int array[a];
    fillarray(array, a);
    std::cout << &array[0] << std::endl;
    std::cout << &array[4] << std::endl;
    std::cout << *maxValuePtr(array, a) << " " << maxValuePtr(array, a) << std::endl;
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    return 0;
}

void fillarray(int array[], int a) {
    for (int i = 0; i < a; i++) {
        std::cout << "Give me the " << (i + 1) << ". number of the array" << std::endl;
        std::cin >> array[i];
    }
}

int *maxValuePtr(int array[], int a) {
    int max = 0;
    int *maxptr = nullptr;
    for (int i = 0; i < a; i++) {
        if (array[i] > max) {
            max = array[i];
            maxptr = &array[i];

        }

    }
    return maxptr;

}