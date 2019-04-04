#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    std::string animals [3] = { "koal" , "pand" , "zebr"};
    for (int i = 0; i < 3; i++){
        animals [i] += "a";
    }
    std::cout << animals [1];

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    return 0;
}