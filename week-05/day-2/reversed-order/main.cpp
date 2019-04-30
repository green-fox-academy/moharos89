#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void fileOpen(std::string fileName);
std::vector<std::string> reverser(std::vector<std::string> lineVector);
void printer(std::vector<std::string> newLines);

int main() {

    fileOpen("../reversed-order.txt");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void fileOpen(std::string fileName) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    try {
        file.open(fileName);
        std::string line;
        std::vector<std::string> lineVector;
        while (std::getline(file , line)) {
            lineVector.push_back(line += "\n");
        }
        printer(reverser(lineVector));

        file.close();

    } catch (std::exception e){
        std::cerr << e.what() << std::endl;
    }

}

std::vector<std::string> reverser(std::vector<std::string> lineVector) {
    std::vector<std::string> newLine;
    auto vectorIt = lineVector.rbegin();
    for (; vectorIt != lineVector.rend(); vectorIt++) {
        newLine.push_back(*vectorIt);
    }
    return newLine;
}

void printer(std::vector<std::string> newLines) {
    for (int i = 0; i < newLines.size() ; ++i) {
        std::cout << newLines[i];
    }

}
