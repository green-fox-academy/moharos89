#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

void fileOpen(std::string fileName);

std::string shreder(std::string line);

std::vector<std::string> mostCommonNumbers(std::map<std::string, int> *lottoNumbersMap);

void printer(std::vector<std::string> mostCommon);


int main() {
    fileOpen("../lottery.csv");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void fileOpen(std::string fileName) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    try {
        file.open(fileName);
        std::string line;
        std::map<std::string, int> lottoNumbersMap;
        while (std::getline(file, line)) {
            std::string numbers;
            std::string fiveNumber = shreder(line);
            std::istringstream ss(fiveNumber);
            while (std::getline(ss, numbers, ';')) {
                lottoNumbersMap[numbers]++;
            }
        }

        printer(mostCommonNumbers(&lottoNumbersMap));


        file.close();

    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

}

std::string shreder(std::string line) {
    std::string newLine;
    std::istringstream ss(line);
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine, ';');
    std::getline(ss, newLine);
    return newLine;
}


std::vector<std::string> mostCommonNumbers(std::map<std::string, int> *lottoNumbersMap) {
    std::vector<std::string> mostCommonNumber = {"0", "0", "0", "0", "0"};
    std::vector<int> numbers = {0, 0, 0, 0, 0};
    auto mapIt = lottoNumbersMap->begin();
    for (; mapIt != lottoNumbersMap->end(); mapIt++) {
        if (mapIt->second > numbers[0]) {
            numbers[0] = mapIt->second;
            mostCommonNumber[0] = mapIt->first;
        }
    }
    auto mapIt1 = lottoNumbersMap->begin();
    for (; mapIt1 != lottoNumbersMap->end(); mapIt1++) {
        if (mapIt1->second > numbers[1] && numbers[0] > mapIt1->second) {
            numbers[1] = mapIt1->second;
            mostCommonNumber[1] = mapIt1->first;
        }
    }
    auto mapIt2 = lottoNumbersMap->begin();
    for (; mapIt2 != lottoNumbersMap->end(); mapIt2++) {
        if (mapIt2->second > numbers[2] && numbers[1] > mapIt2->second) {
            numbers[2] = mapIt2->second;
            mostCommonNumber[2] = mapIt2->first;
        }
    }
    auto mapIt3 = lottoNumbersMap->begin();
    for (; mapIt3 != lottoNumbersMap->end(); mapIt3++) {
        if (mapIt3->second > numbers[3] && numbers[2] > mapIt3->second) {
            numbers[3] = mapIt3->second;
            mostCommonNumber[3] = mapIt3->first;
        }
    }
    auto mapIt4 = lottoNumbersMap->begin();
    for (; mapIt4 != lottoNumbersMap->end(); mapIt4++) {
        if (mapIt4->second > numbers[4] && numbers[3] > mapIt4->second) {
            numbers[4] = mapIt4->second;
            mostCommonNumber[4] = mapIt4->first;
        }
    }
    return mostCommonNumber;
}

void printer(std::vector<std::string> mostCommon) {
    for (int i = 0; i < mostCommon.size(); ++i) {
        std::cout << mostCommon[i] << std::endl;
    }

}
