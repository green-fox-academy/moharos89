#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    for (int a = 0; a < 500; a++) {
        if (a % 2 != 0) {
            std::cout << a << std::endl;
        }
    }

    return 0;
}