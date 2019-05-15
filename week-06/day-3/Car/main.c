#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {
    VOLVO, TOYOTA, LAND_ROVER, TESLA
};

struct car {
    enum car_type type;
    double km;
    double gas;
};

const char *getType(enum car_type type)
{
    switch (type)
    {
        case VOLVO :
            return "Volvo";
        case TOYOTA :
            return "Toyota";
        case LAND_ROVER:
            return "Land_Rover";
        case TESLA:
            return "Tesla";
    }
}

void printCarInfo(struct car *automobile)
{
    printf("Car type: %s\n", getType(automobile->type));
    printf("Car has: %.1f km in it.\n", automobile->km);
    if (automobile->type != 3) {
        printf("Car has: %.1f gas.\n", automobile->gas);
    }
}

int main()
{
    struct car automobile;
    automobile.type = 3;
    printCarInfo(&automobile);
    struct car automobile2;
    automobile2.type = VOLVO;
    printCarInfo(&automobile2);
    return 0;
}

