#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";
    int *aptr = &a;
    double *bptr = &b;
    std::string *nameptr = &name;

    std::cout << aptr << std::endl;
    std::cout << bptr << std::endl;
    std::cout << nameptr << std::endl;
    std::cout << *aptr << std::endl;
    std::cout << *bptr << std::endl;
    std::cout << *nameptr << std::endl;


    return 0;
}