#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int a;
 std::cout << "write your favorite number" << std::endl;
 std::cin >> a;
 if ((a % 2) == 0) {
     std::cout << "Even" << std::endl;
 } else {
     std::cout << "Odd" << std::endl << std::endl;
 }
     int b;
     std::cout << "Write down on number!" << std::endl;
     std::cin >> b;
     if (b <= 0) {
       std::cout << "Not enough" << std::endl;
     } else if (b == 1) {
         std::cout << "One" << std::endl;
     } else if (b ==2) {
         std::cout << "Two" << std::endl;
     } else {
         std::cout << "A lot" << std::endl;
     }





    return 0;
}