#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct {
    char address[30];
    int price;
    int numberOfRooms;
    float area;
} house_t;

int worthTobuy(house_t *house);
int worthToBuyAll(house_t house[] , int numberOfHouses);


int main()
{
    house_t house1;
    house_t house2;
    house_t house3;
    house1.area = 10;
    house2.area = 20;
    house3.area = 30;
    house1.price = 4010;
    house2.price = 7000;
    house3.price = 12000;
    house_t houseArray[] = {house1 , house2 , house3};
    int numberOfHouses = sizeof(houseArray) / sizeof(houseArray[0]);
    printf("There are %d house worth to buy.\n" , worthToBuyAll(houseArray , numberOfHouses));

    return 0;
}

int worthTobuy(house_t *house)
{
    float temp = house->area * 400;
    if (house->price < temp) {
        return 1;
    } else {
        return 0;
    }
}

int worthToBuyAll(house_t house[], int numberOfHouses)
{
    int counter = 0;
    for (int i = 0; i < numberOfHouses; ++i) {
        if(worthTobuy(&house[i])) {
            counter++;
        }
    }
    return counter;
}
