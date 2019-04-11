#include <iostream>

int adder(int);

int main() {

    int n = 20;
    adder(n);
    std::cout << adder(n) << std::endl;
    return 0;
}

int adder(int n) {
    if (n <= 0){
        return 0;
    } else {
        return n + adder(n - 1);
    }

}
