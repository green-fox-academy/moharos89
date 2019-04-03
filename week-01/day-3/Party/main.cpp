#include <iostream>

int main(int argc, char* args[]) {

    int a;
    int b;
    std::cout <<"How many girls at the party?" << std::endl;
    std::cin >> a;
    std::cout <<"How many boys at the party?" << std::endl;
    std::cin >> b;
    if (a == 0) {
        std::cout << "Sausage party" << std::endl;
    }else if ((a / b == 1) && (a + b >= 20)) {
        std::cout << "The party is exelent!" << std::endl;
    } else if (a / b != 1 && (a + b >= 20)) {
        std::cout << "Quite cool party" << std::endl;
    } else if((a + b) < 20) {
        std::cout << "Avarege party..." << std::endl;
    } else {

    }






    return 0;
}