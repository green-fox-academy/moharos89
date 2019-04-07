#include <iostream>
#include <string>

void factorio (int , int&);

int main(int argc, char* args[]) {
    int b;
    std::cout << "I want a number!" << std::endl;
    std::cin >> b;

    int a;

    factorio (b , a);

    std::cout << a << std::endl;

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    return 0;
}

void factorio (int a , int& b) {
    int f = 1;
    for (int d = 0; d <= a; d++) {
        if (d != 0){
            f *= d;
        }
    }
    b = f;
    std::cout << b << std::endl;
}