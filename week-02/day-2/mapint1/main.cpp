#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    if (myMap.empty() == 1) {
        std::cout << "I'm empty" << std::endl;
    } else {
        std::cout << "I have something" << std::endl;
    }
    myMap.insert(std::make_pair(97, "a"));
    myMap.insert(std::make_pair(98, "b"));
    myMap.insert(std::make_pair(99, "c"));
    myMap.insert(std::make_pair(65, "A"));
    myMap.insert(std::make_pair(66, "B"));
    myMap.insert(std::make_pair(67, "C"));

    std::map<int, std::string>::iterator mapIt = myMap.begin();
    for (mapIt; mapIt != myMap.end(); mapIt++) {
        std::cout << mapIt->first << std::endl;
    }
    std::map<int, std::string>::iterator mapIt2 = myMap.begin();
    for (mapIt2; mapIt2 != myMap.end(); mapIt2++) {
        std::cout << mapIt2->second << std::endl;

    }
    myMap.insert(std::make_pair (68 , "D"));
    std::cout << myMap.size() << std::endl;
    std::cout << myMap[99] << std::endl;
    myMap.erase(97);
    if (myMap.count(100) == 1) {
        std::cout << myMap[100] << " Yes it is." << std::endl;
    } else {
        std::cout << "There are no such thing!" << std::endl;
    }
    myMap.clear();




    return 0;
}