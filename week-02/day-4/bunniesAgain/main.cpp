#include <iostream>

int bunnies (int n);
int main() {
    int n = 4;


    std::cout << bunnies(n) << std::endl;
    return 0;
}
int bunnies ( int n){
    if (n == 1) {
        return 2;
    } else if (n % 2 == 0){
        return 3 + bunnies (n -1);
    } else {
        return 2 + bunnies (n - 1);
    }
}