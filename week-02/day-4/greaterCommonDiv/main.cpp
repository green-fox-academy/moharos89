#include <iostream>

int greatDiv(int, int, int);
int greatDiv2(int, int);

int main() {
    int a = 45;
    int b = 60;
    int n = 1;
    if (a < b) {
        n = a;
    } else {
        n = b;
    }
    std::cout << greatDiv(a, b, n) << std::endl;
    std::cout << greatDiv2(a, b) << std::endl;
    return 0;
}

int greatDiv(int a, int b, int n) {
    if (a % n == 0 && b % n == 0) {
        return n;
    } else {
        greatDiv(a, b, n - 1);
    }

}
int greatDiv2(int a, int b) {
    if (a % b == 0) {
        return b;
    } else greatDiv2(b , a % b);

}
