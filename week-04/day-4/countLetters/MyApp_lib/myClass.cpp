//
// Created by Bence on 2019.04.24..
//

#include "myClass.h"


std::map<std::string, int> dictionaryMaker(std::string word) {
    std::map<std::string , int> dictionary;
    for (int i = 0; i < uniquletter(word).size(); i++) {
        int count = 0;
        for (int j = 0; j < word.size(); j++){
            if (uniquletter(word)[i] == word[j]) {
                count += 1;
            }
        }
        std::string temp = "";
        temp.push_back(uniquletter(word)[i]);
        dictionary[temp] = count;
    }

    return dictionary;
}

std::vector<char> uniquletter(std::string word) {
    std::vector<char> uniqueletters = {};
    for (int i = 0; i < word.size(); i++) {
        if (uniqueLetterChecker(word[i], uniqueletters)) {
            uniqueletters.push_back(word[i]);
        }

    }
    return uniqueletters;
}

bool uniqueLetterChecker(char char1, std::vector<char> uniqueletters) {
    for (int i = 0; i < uniqueletters.size(); i++) {
        if (char1 == uniqueletters[i]) {
            return false;
        }
    }
    return true;
}
