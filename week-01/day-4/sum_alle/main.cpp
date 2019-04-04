#include <iostream>
#include <string>

int main(int argc, char* args[]) {
    int ai[5] = {3 , 4 , 5 , 6 , 7};
    int  c = 0;
    std::cout << c << std::endl;

    for(int i = 0; i < 5; i++){
        c += ai[i];
    }
    std::cout << c;


    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`

    return 0;
}