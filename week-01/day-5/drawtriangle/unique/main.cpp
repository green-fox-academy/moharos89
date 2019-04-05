#include <iostream>
#include <string>

void unique(int[]);

void print(int[]);

int main(int argc, char *args[]) {

    int list[] = {1, 11, 34, 11, 52, 61, 1, 34};
    unique(list);
    print(list);


    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    //int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    //std::cout << (unique(numbers)) << std::endl;
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}

void unique(int array[]) {
    int a = 8; //sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < a; i++) {
        if (i != 0) {
            for (int j = 0; j < i; j++) {
                if (array[i] == array[i - (1 + j)]) {
                    break;
                } else if (i == j + 1) {
                    std::cout << array[i] << " ";
                    break;
                }
            }
        } else {
            std::cout << array[i] << " ";
        }
    }

}

void print(int array[]) {
    int a = 8; //sizeof(array)/sizeof(array[0]);
    std::cout << std::endl;
    for (int i = 0; i <= a; i++ ) {
        if (i != a) {
            std::cout << array[i] << " ";
        } else {
            std::cout << std::endl;
        }
    }
}