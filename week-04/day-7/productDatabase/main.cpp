#include <iostream>
#include <map>

int cost(std::map<std::string , int> *shoppingList , std::string name);
std::string mostExpensive(std::map<std::string , int> *shoppingList);
double averagePrice(std::map<std::string , int> *shoppingList);
int priceBelow(std::map<std::string , int> *shoppingList);
void exactPrice(std::map<std::string , int> *shoppingList);
std::string cheapest(std::map<std::string , int> *shoppingList);
void priceBelowName(std::map<std::string, int> *shoppingList);
void priceAboveName(std::map<std::string, int> *shoppingList);


int main() {
    std::map<std::string , int> shoppingList;
    shoppingList["eggs"] = 200;
    shoppingList["milk"] = 200;
    shoppingList["fish"] = 400;
    shoppingList["apples"] = 150;
    shoppingList["bread"] = 50;
    shoppingList["chicken"] = 550;

    std::cout << "The fish cost: " << cost(&shoppingList , "fish") << std::endl;
    std::cout << "The most expensive product is the " << mostExpensive(&shoppingList) << std::endl;
    std::cout << "Average price is: " << averagePrice(&shoppingList) << std::endl;
    std::cout << "You can buy " << priceBelow(&shoppingList) << " thing(s) below 300" <<std::endl;
    exactPrice(&shoppingList);
    std::cout << "The most cheapest product is the " << cheapest(&shoppingList) << std::endl;
    priceBelowName(&shoppingList);
    priceAboveName(&shoppingList);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int cost(std::map<std::string, int> *shoppingList, std::string name) {
    return shoppingList->at(name);
}

std::string mostExpensive(std::map<std::string, int> *shoppingList) {
    std::map<std::string, int>::iterator mapIt = shoppingList->begin();
    std::map<std::string, int>::iterator tempIt= shoppingList->begin();
    for(mapIt; mapIt != shoppingList->end(); mapIt++) {
        if(mapIt->second > tempIt->second) {
            tempIt = mapIt;
        }
    }
    return tempIt->first;
}

double averagePrice(std::map<std::string, int> *shoppingList) {
    std::map<std::string, int>::iterator mapIt = shoppingList->begin();
    double sum = 0;
    for (mapIt;  mapIt != shoppingList->end() ; mapIt++) {
        sum += mapIt->second;
    }
    return sum / shoppingList->size();
}

int priceBelow(std::map<std::string, int> *shoppingList) {
    std::map<std::string, int>::iterator mapIt = shoppingList->begin();
    int price = 300;
    int counter = 0;
    for (mapIt; mapIt != shoppingList->end(); mapIt++) {
        if (price > mapIt->second) {
            counter++;
        }
    }
    return counter;
}

void exactPrice(std::map<std::string, int> *shoppingList) {
    std::map<std::string, int>::iterator mapIt = shoppingList->begin();
    for (mapIt; mapIt != shoppingList->end(); mapIt++) {
        if (125 == mapIt->second) {
            std::cout << "You can buy " << mapIt->first << std::endl;
            return;
        }
    }
    std::cout << "You can buy anything for exactly 125." << std::endl;

}

std::string cheapest(std::map<std::string, int> *shoppingList) {
    std::map<std::string, int>::iterator mapIt = shoppingList->begin();
    std::map<std::string, int>::iterator tempIt= shoppingList->begin();
    for(mapIt; mapIt != shoppingList->end(); mapIt++) {
        if(mapIt->second < tempIt->second) {
            tempIt = mapIt;
        }
    }
    return tempIt->first;
}
void priceBelowName(std::map<std::string, int> *shoppingList) {
    std::map<std::string, int>::iterator mapIt = shoppingList->begin();
    int price = 201;
    for (mapIt; mapIt != shoppingList->end(); mapIt++) {
        if (price > mapIt->second) {
            std::cout << mapIt->first << std::endl;
        }
    }
}
void priceAboveName(std::map<std::string, int> *shoppingList) {
    std::map<std::string, int>::iterator mapIt = shoppingList->begin();
    int price = 150;
    for (mapIt; mapIt != shoppingList->end(); mapIt++) {
        if (price < mapIt->second) {
            std::cout << mapIt->first << " " << mapIt->second << std::endl;
        }
    }
}