#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void fileOpen(std::string fileName);
std::string reverser(std::vector<char> letters);
void printer(std::string line);

int main() {
    fileOpen("../reversed-lines.txt");


    // Create a program that decrypts the file called "reversed-lines.txt",
    // and pritns the decrypred text to the terminal window.

    return 0;
}

void fileOpen(std::string fileName) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    try {
        file.open(fileName);
        std::string line;
        while (std::getline(file , line)) {
            std::vector<char> letters = {};
            for (int i = 0; i < line.size() ; ++i) {
                letters.push_back(line[i]);
            }
            printer(reverser(letters));
        }

    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

}

std::string reverser(std::vector<char> letters) {
    auto linerIt = letters.rbegin();
    std::string newLine = "";
    for (; linerIt < letters.rend() ; linerIt++) {
        newLine.push_back(*linerIt);
    }
    return newLine;
}

void printer(std::string line) {
    std::cout << line << std::endl;

}
