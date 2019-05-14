//
// Created by Bence on 2019.05.13..
//

#include "functions.h"



std::string numberConverter(int number)
{
    std::string result = "";
    if (number < 20 && number > 0) {
        Numbers numbers;
        numbers.fillMap();
        auto mapIt = numbers._numbers.begin();
        for (; mapIt != numbers._numbers.end(); mapIt++) {
            if (number == mapIt->first) {
                result += mapIt->second;
            }
        }
    }
    if (number >= 20 && number < 100) {
        Numbers numbers;
        numbers.fillDecades();
        result += numbers._decades[number / 10];
        result += "-";
        result += numberConverter(number % 10);
    }
    return result;
}
