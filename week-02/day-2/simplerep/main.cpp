#include <iostream>
#include <string>

int main(int argc, char *args[]) {
    std::string example("In a dishwasher far far away");

    int n = example.find("dishwasher");
    std::cout << n << std::endl;
    std::string replace = "dishwasher";
    int sizerep = replace.size();
    std::cout << sizerep << std::endl;

    //int b = example.size();

    example.replace(n , sizerep , "galaxy");

    // I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
    // Please fix it for me!
    // Expected output: In a galaxy far far away

    std::cout << example << std::endl;
    return 0;
}