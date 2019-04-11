#include <iostream>

int power (int , int);

int main() {

    int base = 3;
    int n = 4;

    std::cout << power(base , n) << std::endl;
    return 0;
}

int power(int base , int n){
    if (n < 1) {
        return 1;
    } else {
        return base * power(base , n -  1);
    }
}