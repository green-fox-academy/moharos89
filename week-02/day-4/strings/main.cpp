#include <iostream>
#include <string>

std::string changer(std::string);

int main() {

    std::string proba = "xxxxxXwhxxxx";


    std::cout << changer(proba) << std::endl;
    return 0;
}

std::string changer(std::string proba) {

    if (proba.find("x") == std::string::npos) {
        return proba;

    } else {
        int temp = proba.find("x");
        std::cout << temp;
        proba.erase(temp , 1);
        proba.insert(temp , "y");
        return changer(proba);
    }


}