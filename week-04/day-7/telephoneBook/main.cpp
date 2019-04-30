#include <iostream>
#include <map>
#include <string>

std::string numberSearcher(std::map<std::string , std::string> *telephoneBook , std::string name);
std::string nameSearcher(std::map<std::string , std::string> *telephoneBook , std::string number);
void existSearcher(std::map<std::string , std::string> &telephoneBook , std::string name);

int main() {

    std::map<std::string , std::string> telephoneBook;
    telephoneBook["William A. Lathan"] = "405-709-1865";
    telephoneBook["John K. Miller"] = "402-247-8568";
    telephoneBook["Hortensia E. Foster"] = "606-481-6467";
    telephoneBook["Amanda D. Newland"] = "319-243-5613";
    telephoneBook["Brooke P. Askew"] = "307-687-2982";

    std::cout << numberSearcher(&telephoneBook , "John K. Miller") << std::endl;
    std::cout << nameSearcher(&telephoneBook , "307-687-2982") << std::endl;
    existSearcher(telephoneBook , "Chris E. Myers");
    return 0;
}

std::string numberSearcher(std::map<std::string, std::string> *telephoneBook, std::string name) {
    if (telephoneBook->find(name) == telephoneBook->end()) {
        return "There is is no such a name in the telephone book";
    } else {
        return telephoneBook->at(name);
    }
}

std::string nameSearcher(std::map<std::string, std::string> *telephoneBook, std::string number) {
    std::map<std::string , std::string>::iterator mapIt = telephoneBook->begin();
    for (mapIt; mapIt != telephoneBook->end() ; mapIt++) {
      if(mapIt->second == "307-687-2982") {
          return mapIt->first;
      }
    }
    return "There is no such a number in the telephone book.";

}

void existSearcher(std::map<std::string, std::string> &telephoneBook, std::string name) {
    if(telephoneBook.find(name) != telephoneBook.end()) {
        std::cout << "The number of " << name << " is: " << telephoneBook.find(name)->second << std::endl;
    } else {
        std::cout << "There in no such a name in the telephone book." << std::endl;
    }

}
