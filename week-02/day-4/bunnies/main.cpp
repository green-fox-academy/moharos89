#include <iostream>
int bunnies (int);


int main() {

    int num = 30;


    std::cout << bunnies(num) << std::endl;
    return 0;
}
int bunnies(int num) {
    if (num == 1) {
        return 2;
    } else {
        return 2 + bunnies(num - 1);
    }
}
