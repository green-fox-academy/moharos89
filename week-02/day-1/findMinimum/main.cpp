#include <iostream>

int *findmin(int [], int);


int main() {
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int numberssize = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << &numbers[5] << std::endl;

    int * c = findmin(numbers, numberssize);

    std::cout << c << std::endl;

    return 0;
}

int *findmin(int numbers[], int numberssize) {
    int min = numbers[0];
    int *minptr = &numbers[0];
    for (int i = 0; i < numberssize; i++){
        if (numbers[i] < min) {
            min = numbers[i];
            minptr = &numbers[i];
        }
    }
    std::cout << min << std::endl;
    return minptr;
}
