#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct {
    char name[30];
    float price;
    float weight;
} sandwich_t;

float orderPrice(sandwich_t sandwich , int number);

int main()
{
    sandwich_t sandwich;
    sandwich.price = 1.3;
    printf("The price of your order is: %.1f.\n" , orderPrice(sandwich , 5));

    return 0;
}

float orderPrice(sandwich_t sandwich, int number)
{
    float temp = sandwich.price * number;
    return temp;
}