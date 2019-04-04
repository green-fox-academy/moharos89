#include <iostream>
#include <string>

int doubling (int);

int main(int argc, char* args[]) {

    int baseNum = 123;
    int c = doubling (baseNum);
    std::cout << c << std::endl;
    // - Create an integer variable named `baseNum` and assign the value `123` to it
    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    // - Print the result of `doubling(baseNum)`

    return 0;
}
int doubling (int a) {
    int b = a *= 2;
    return b;

}