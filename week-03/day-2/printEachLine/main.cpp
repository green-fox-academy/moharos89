
#include <iostream>
#include <fstream>
#include <string>

int main () {
std::ofstream myFile1;
myFile1.open("../my-text.txt");
if (myFile1.is_open()) {
    myFile1 << "My name is Bence \n";
    myFile1 << "I'm  chemist \n";

} else {
    std::cout << "The order can not be executed!";
}

myFile1.close();
    std::ifstream myFile;
    myFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        myFile.open("../my-text.txt");
        if (myFile.is_open()) {
            std::string line;
            while(std::getline(myFile , line)) {
                std::cout << line << std::endl;
            }
            myFile.close();
        }
    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    }
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    return 0;
}