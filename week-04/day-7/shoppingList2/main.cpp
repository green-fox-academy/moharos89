#include <iostream>
#include <map>
#include <string>
#include <vector>

double price(std::map<std::string, int> *list, std::map<std::string, double> *shop);

void buysMore(std::map<std::string, int> *list, std::map<std::string, int> *list2, std::string thing);

void buysMoreDiff(std::map<std::string, int> *list, std::map<std::string, int> *list2);

void buysMorePrice(std::map<std::string, int> *list, std::map<std::string, int> *alicesList,
                   std::map<std::string, double> *shop);

int main() {
    std::map<std::string, double> shop;
    shop["milk"] = 1.07;
    shop["rice"] = 1.59;
    shop["eggs"] = 3.14;
    shop["cheese"] = 12.60;
    shop["chicken breasts"] = 9.40;
    shop["apples"] = 2.31;
    shop["tomato"] = 1.75;
    shop["onion"] = 1.10;

    std::map<std::string, int> bobsList;
    bobsList["milk"] = 3;
    bobsList["rice"] = 2;
    bobsList["eggs"] = 2;
    bobsList["cheese"] = 1;
    bobsList["chicken breasts"] = 4;
    bobsList["apples"] = 1;
    bobsList["tomato"] = 2;
    bobsList["potato"] = 1;

    std::map<std::string, int> alicesList;
    alicesList["rice"] = 1;
    alicesList["eggs"] = 5;
    alicesList["chicken breasts"] = 2;
    alicesList["apples"] = 1;
    alicesList["tomato"] = 10;

    std::map<std::string, std::map<std::string, int>> names;
    names["Bob"] = bobsList;
    names["Alice"] = alicesList;

    std::cout << "Bob pays: " << price(&bobsList, &shop) << std::endl;
    std::cout << "Alice pays: " << price(&alicesList, &shop) << std::endl;
    buysMore(&bobsList, &alicesList, "rice");
    buysMore(&bobsList, &alicesList, "potato");
    buysMoreDiff(&bobsList, &alicesList);
    buysMorePrice(&bobsList, &alicesList, &shop);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}

double price(std::map<std::string, int> *list, std::map<std::string, double> *shop) {
    double sum = 0;
    auto mapIt = list->begin();
    for (; mapIt != list->end(); mapIt++) {
        auto shopIt = shop->begin();
        for (; shopIt != shop->end(); shopIt++) {
            if (mapIt->first == shopIt->first) {
                sum += mapIt->second * shopIt->second;
            }
        }
    }
    return sum;
}

void buysMore(std::map<std::string, int> *list, std::map<std::string, int> *list2, std::string thing) {
    if (list->find(thing)->second > list2->find(thing)->second) {
        std::cout << "Bob buys more " << thing << std::endl;
    } else {
        std::cout << "Alice buys more " << thing << std::endl;
    }
}

void buysMoreDiff(std::map<std::string, int> *list, std::map<std::string, int> *list2) {
    if (list->size() > list2->size()) {
        std::cout << "Bob buys more different products." << std::endl;
    } else {
        std::cout << "Alice buys more different products." << std::endl;
    }

}

void buysMorePrice(std::map<std::string, int> *bobsList, std::map<std::string, int> *alicesList,
                   std::map<std::string, double> *shop) {
    if (price(bobsList, shop) > price(alicesList, shop)) {
        std::cout << "Bob buys more products" << std::endl;
    } else {
        std::cout << "Alice buys more products" << std::endl;
    }

}
