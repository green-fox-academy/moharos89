#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"
void filewriter(std::string, std::string, int);

int main() {

    std::cout << "Give me a path, a word you want to write and a number for multiplications" << std::endl;
    std::string path;
    std::string sentence;
    int num;
    std::cin >> path >> sentence >> num;
    filewriter(path, sentence, num);

    return 0;
}

void filewriter(std::string path, std::string sentence, int num) {
    std::ofstream file(path);
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        if (file.is_open()) {
            for (int i = 0; i < num; i++) {
                file << sentence << "\n";
            }
        } else {
            std::cout << "Mester the file is can not be written" << std::endl;
        }
    } catch (std::ofstream::failure& e) {
        std::cout << e.what() << std::endl;
    }
}