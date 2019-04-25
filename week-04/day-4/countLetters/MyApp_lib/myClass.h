//
// Created by Bence on 2019.04.24..
//

#ifndef APPLES_MYCLASS_H
#define APPLES_MYCLASS_H

#include <string>
#include <vector>
#include <map>

std::map<std::string , int> dictionaryMaker (std::string word);
std::vector<char> uniquletter(std::string word);
bool uniqueLetterChecker (char char1 , std::vector<char> uniqueletters);


#endif //APPLES_MYCLASS_H
