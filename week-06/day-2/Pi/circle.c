//
// Created by Bence on 2019.05.14..
//

#include "circle.h"

float circleArea(float radius)
{
    return radius * radius * PI;
}

float circumference(float *radius)
{
    return 2 * *radius * PI;
}
