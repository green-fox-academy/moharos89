#include <iostream>
#include <time.h>
#include "animalShelter.h"
#include "cat.h"
#include "dog.h"
#include "parrot.h"


int main()
{
    srand(time(nullptr));
    AnimalShelter shelter1;
    Cat cat1;
    Dog dog1;
    Parrot parrot1;
    Dog dog2("Bucky" , true);
    Cat cat2("Black");
    shelter1.rescue(&cat1);
    shelter1.rescue(&dog1);
    shelter1.rescue(&parrot1);
    shelter1.rescue(&dog2);
    shelter1.rescue(&cat2);
    shelter1.toString();
    shelter1.addAdopter("Barna");
    shelter1.addAdopter("Zoltan");
    shelter1.addAdopter("Erno");
    shelter1.toString();
    dog2.toString();
    cat1.toString();
    shelter1.heal();
    shelter1.toString();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}