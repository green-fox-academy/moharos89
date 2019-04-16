#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful
bool copyf(std::string, std::string);

int main() {

    std::cout << "Give me a file path" << std::endl;
    std::string base;
    std::cin >> base;
    std::cout << "Give me the file path for the copy" << std::endl;
    std::string copy;
    std::cin >> copy;
    if (copyf(base, copy)) {
        std::cout << "I have done it!" << std::endl;
    } else {
        std::cout << "Master the process is not completed" << std::endl;
    }
    return 0;
}

bool copyf(std::string base, std::string copy) {
    std::ifstream file1;
    file1.exceptions(std::ifstream::badbit);
    std::ofstream file2;
    file2.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        file1.open(base);
        file2.open(copy);
        if (file1.is_open() && file2.is_open()) {
            std::string temp;
            while (std::getline(file1, temp)) {
                file2 << temp << "\n";
            }
        } else {
            return false;
        }

        file1.close();
        file2.close();
        return true;

    } catch (std::ifstream::failure& e) {
        return false;
    }
}