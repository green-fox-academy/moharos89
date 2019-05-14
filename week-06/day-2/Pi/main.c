#include <stdio.h>
#include "circle.h"





int main()
{
    float radius = 3;
    printf("%.2f\n" , circleArea(radius));
    printf("%.2f\n" , circumference(&radius));

    // define a variable called PI with the value of 3.14
    // create a function which takes the radius of a circle as a parameter
    // and return the area of that cirle
    // area = radius * radius * PI
    return 0;
}
