#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.
void reader(std::string file);

void shredder(std::string, std::vector<std::string> &);

double getPost(std::string);

int main() {

    reader("../log.txt");
    std::cout << getPost("../log.txt") << std::endl;
    return 0;
}

void reader(std::string file) {
    std::ifstream filelines(file);
    std::string line;
    std::vector<std::string> ips;
    while (std::getline(filelines, line)) {
        std::istringstream firstPart(line);
        std::string text;
        shredder(line, ips);

    }
    std::cout << ips[1] << std::endl;
}

void shredder(std::string line, std::vector<std::string> &ips) {
    if (line.find("   ")) {
        int space = line.find("   ");
        std::string temp;
        temp = line.substr(space + 3, 11);
        //std::cout << temp << std::endl;
        ips.push_back(temp);
    }


}

double getPost(std::string file) {
    double get = 0.0;
    double post = 0.0;
    std::ifstream list(file);
    std::string line;
    while (std::getline(list, line)) {
        if (line.find("GET") != std::string::npos) {
            get += 1;
            //std::cout << get << std::endl;
        } else if (line.find("POST") != std::string::npos) {
            post += 1;
            //std::cout << post << std::endl;
        }
    }
    return get/post;


}