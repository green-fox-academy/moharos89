//
// Created by Bence on 2019.05.13..
//

#ifndef ANAGRAM_NUMBERS_H
#define ANAGRAM_NUMBERS_H

#include <map>


class Numbers {
public:
    void fillMap();
    void fillDecades();
    std::map<int , std::string> _numbers;
    std::map<int , std::string> _decades;


};


#endif //ANAGRAM_NUMBERS_H
