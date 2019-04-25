//
// Created by Bence on 2019.04.24..
//

#ifndef APPLES_MYCLASS_H
#define APPLES_MYCLASS_H

#include <string>
#include <vector>


class myClass {
public:
    std::string getApple();
    int sum(std::vector<int> *numbers);
    std::vector<int> _numbers = {1 , 2 , 3 , 4};
};


#endif //APPLES_MYCLASS_H
