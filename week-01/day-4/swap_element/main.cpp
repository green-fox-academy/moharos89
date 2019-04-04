#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    std::string abc[3] = {"first" , "second" , "third"};
    std::string c = abc [0];
    abc [0] = abc[2];
    abc [2] = c;
    std::cout << abc[2];

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`

    return 0;
}