#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void fileOpen(std::string fileName);
std::string decrypter(std::string line);
void resultPinter(std::string string);

int main() {

    fileOpen("../dublicated-chars.txt");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void fileOpen(std::string fileName) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    try{
        file.open(fileName);
        std::string line;
        while (std::getline(file , line)) {
            resultPinter(decrypter(line));
        }


    } catch (std::exception e){
        std::cerr << e.what() << std::endl;
    }

}

std::string decrypter(std::string line) {
    std::string newLine = {};
    for (int i = 0; i < line.size() ; ++i) {
        if(i % 2 == 0) {
            newLine.push_back(line[i]);
        }
    }
    return newLine;
}

void resultPinter(std::string string) {
    std::cout << string << std::endl;

}

