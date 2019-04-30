#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void fileopen(std::string fileName);

std::vector<char> decrypter(std::vector<std::string> line);

void printer(std::vector<char> newLine);

int main() {

    fileopen("../encoded-lines.txt");

    // Create a program that decrypts the file called "encoded-lines.txt",
    // and pritns the decrypred text to the terminal window.

    return 0;
}

void fileopen(std::string fileName) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    try {
        file.open(fileName);
        std::string line;
        std::vector<std::string> lineVector;
        while (std::getline(file, line)) {
            lineVector.push_back(line += "\n");

        }
        printer(decrypter(lineVector));
        file.close();

    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

}

std::vector<char> decrypter(std::vector<std::string> line) {
    std::vector<char> newLine;
    for (int i = 0; i < line.size(); i++) {
        for (int j = 0; j < line[i].size(); j++) {
            if (line[i][j] != '\n' && line[i][j] != ' ') {
                newLine.push_back(line[i][j] - 1);
            } else {
                newLine.push_back((line[i][j]));
            }
        }
    }
    return newLine;

}

void printer(std::vector<char> newLine) {
    for (int i = 0; i < newLine.size(); ++i) {
        std::cout << newLine[i];
    }
}
