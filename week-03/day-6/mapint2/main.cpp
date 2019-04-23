#include <iostream>
#include <map>
#include <string>

int main() {

    std::map<std::string, std::string> myMap;
    myMap.insert(std::pair<std::string, std::string>("978-1-60309-452-8", "A letter to Jo"));
    myMap["978-1-60309-459-7"] = "Lupus";
    myMap["978-1-60309-444-3"] = "Red Panda and Moon Bear";
    myMap["978-1-60309-461-0"] = "The Lab";

    std::map<std::string, std::string>::iterator mapIt = myMap.begin();
    for (mapIt; mapIt != myMap.end(); mapIt++) {
        std::cout << mapIt->second << " (ISBN: " << mapIt->first << ")" << std::endl;
    }
    myMap.erase("978-1-60309-444-3");
    mapIt = myMap.begin();
    for (mapIt; mapIt != myMap.end(); mapIt++) {
        if (mapIt->second == "The Lab") {
            myMap.erase(mapIt -> first);
        }
    }
    myMap["978-1-60309-450-4"] = "They Called Us Enemy";
    myMap["978-1-60309-453-5"] = "Why Did We Trust Him?";

    std::map<std::string, std::string>::iterator mapIt2 = myMap.begin();
    for (mapIt2; mapIt2 != myMap.end(); mapIt2++) {
        std::cout << mapIt2->second << " (ISBN: " << mapIt2->first << ")" << std::endl;
    }
    std::map<std::string, std::string>::iterator mapIt3 = myMap.begin();
    for (mapIt3; mapIt3 != myMap.end(); mapIt3++) {
        if (myMap.find("478-0-61159-424-8") != myMap.end()) {
           std::cout << mapIt3 -> first << " is associated with " << mapIt3 -> second << std::endl;

        } else {
            std::cout << "There is no kay as " << mapIt3 -> first << std::endl;
        }
    }
    std::cout << myMap["978-1-60309-453-5"] << std::endl;

    return 0;
}