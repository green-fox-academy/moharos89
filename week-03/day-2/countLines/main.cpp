#include <iostream>
#include <fstream>
#include <string>

int fileLineCounter ( std::string name);

int main () {
    std::cout << "Please write a file name:" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << fileLineCounter (name) << std::endl;
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    return 0;
}
int fileLineCounter (std::string name){

    std::ifstream file;
   // try {
        file.open(name);
        if(file.is_open()) {
            int counter = 0;
            std::string lines;
            while(std::getline(file , lines)){
                std::cout << lines << std::endl;
                counter += 1;
            }
            file.close();
            return counter;
        } else {
            return 0;
        }
   // } catch (std::ifstream::failure& e) {
       // std::cout << e.what() << std::endl;
 //   }
}