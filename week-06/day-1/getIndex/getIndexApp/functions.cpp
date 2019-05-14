//
// Created by Bence on 2019.05.13..
//

#include "functions.h"

int getIndex(std::vector<int> vector, int value)
{
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] == value) {
            return i;
        }
    }
    return -1;
}