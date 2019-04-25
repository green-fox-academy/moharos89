//
// Created by Bence on 2019.04.24..
//

#include "myClass.h"

bool anagram(std::string word1, std::string word2) {
    if(wordSizeChecker(word1 , word2) == false) {
        return false;
    } else if (wordSorter(word1).compare(wordSorter(word2)) == 0){
        return true;
    } else {
        return false;
    }

}

std::string wordSorter(std::string &word) {
    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < word.size() - 1; j++) {
            if (word[j] > word[j + 1]) {
                switcher(word[j], word[j + 1]);
            }
        }
    }
    return word;

}

bool wordSizeChecker(std::string world1, std::string world2) {
    return world1.size() == world2.size();

}

void switcher(char &char1, char &char2) {
    char temp = char1;
    char1 = char2;
    char2 = temp;

}

