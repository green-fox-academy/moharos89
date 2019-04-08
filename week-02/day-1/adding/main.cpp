#include <iostream>

int main() {
    // Add two numbers using pointers

    int a = 20;
    int b = 17;
    int *aptr = &a;
    int *bptr = &b;
    int c = *aptr + *bptr;
    std::cout << c << std::endl;

    return 0;
}