#include <iostream>
#include <math.h>

int sumdigit(int, int);

int sumdigit2(int);

int main() {
    int counter = 1;
    int n = 123;

    std::cout << sumdigit(counter, n) << std::endl;
    std::cout << sumdigit2(n);

    return 0;
}

int sumdigit(int counter, int n) {

    if (n / pow(10, counter) < 1) {
        return n % 10;
    } else {
        return (int) (n / pow(10, counter)) % 10 + sumdigit(counter + 1, n);
    }

}

int sumdigit2(int n) {

    if (n / 10 < 1) {
        return n % 10;
    } else {
        return (n % 10 + sumdigit2(n / 10));
    }
}