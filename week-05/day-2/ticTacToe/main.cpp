#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::string ticTacResult(std::string fileName);

std::string resultMeter(std::vector<std::vector<char>> *ticTac);

int main() {
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    std::cout << ticTacResult("../win-o.txt");
    // should print O

    std::cout << ticTacResult("../win-x.txt");
    // should print X

    std::cout << ticTacResult("../draw.txt");
    // should print draw

    return 0;
}

std::string ticTacResult(std::string fileName) {
    std::ifstream file(fileName);
    file.exceptions(std::ifstream::badbit);
    try {
        std::vector<std::vector<char>> ticTac;
        std::string line;
        while (std::getline(file, line)) {
            std::vector<char> temp = {};
            for (int i = 0; i < line.size(); ++i) {
                temp.push_back(line[i]);
            }
            ticTac.push_back(temp);
        }
        return resultMeter(&ticTac);


    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }
    return "";
}

std::string resultMeter(std::vector<std::vector<char>> *ticTac) {
    std::string result = "";
    if (ticTac->at(0)[0] == ticTac->at(1)[1] && ticTac->at(1)[1] == ticTac->at(2)[2]) {
        result.push_back(ticTac->at(0)[0]);
        return result;
    } else if (ticTac->at(0)[2] == ticTac->at(1)[1] && ticTac->at(1)[1] == ticTac->at(2)[0]) {
        result.push_back(ticTac->at(0)[2]);
        return result;
    }
    for (int i = 0; i < ticTac->size(); ++i) {
        if (ticTac->at(i)[0] == ticTac->at(i)[1] && ticTac->at(i)[1] == ticTac->at(i)[2]) {
            result.push_back(ticTac->at(i)[0]);
            return result;
        } else if (ticTac->at(0)[i] == ticTac->at(1)[i] && ticTac->at(1)[i] == ticTac->at(2)[i]) {
            result.push_back(ticTac->at(0)[i]);
            return result;
        }
    }
    return "draw";
}
