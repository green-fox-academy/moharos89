#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> nameList;
    std::cout << nameList.size() << std::endl;
    nameList.push_back("William");
    if (nameList.empty() == 0) {
        std::cout << "it's not empty" << std::endl;
    } else {
        std::cout << "It's empty" << std::endl;
    }
    nameList.push_back("John");
    nameList.push_back("Amanda");
    std::cout << nameList.size() << std::endl;
    std::cout << nameList.at(2) << std::endl;
    std::vector<std::string>::iterator nameIt = nameList.begin();
    for (nameIt; nameIt != nameList.end(); nameIt++) {
        std::cout << *nameIt << std::endl;
    }
    std::vector<std::string>::iterator nameIt3 = nameList.begin();
    for (nameIt3; nameIt3 != nameList.end(); nameIt3++) {
        std::cout << std::distance(nameList.begin(), nameIt3) + 1 << ". " << *nameIt3 << std::endl;
    }
    std::vector<std::string>::iterator eraser = nameList.begin() + 1;
    nameList.erase(eraser);
    for (nameIt3 = nameList.end(); nameIt3 != nameList.begin() - 1; nameIt3--) {
        std::cout << *nameIt3 << std::endl;

    }

    return 0;
}