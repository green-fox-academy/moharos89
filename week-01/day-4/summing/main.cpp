#include <iostream>
#include <string>

void sum (int&);

int main(int argc, char* args[]) {

    std::cout << " Write a number!" << std::endl;
    int a;
    std::cin >> a;
    sum (a);
    std::cout << a << std::endl;


    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    return 0;
}
void sum (int& a){
    int c = 0;
    for (int b = 0; b <= a; b++){
        c += b;
    }
    a = c;
}