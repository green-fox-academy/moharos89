#include <iostream>
#include <vector>

int sumSpent(std::vector<int> *financeList);

int mostSpent(std::vector<int> *financeList);

int lessSpent(std::vector<int> *financeList);

double averageSpent(std::vector<int> *financeList);

int main() {
    std::vector<int> financeList = {500, 1000, 1250, 175, 800, 120};

    std::cout << sumSpent(&financeList) << std::endl;
    std::cout << mostSpent(&financeList) << std::endl;
    std::cout << lessSpent(&financeList) << std::endl;
    std::cout << averageSpent(&financeList) << std::endl;

    return 0;
}
int sumSpent(std::vector<int> *financeList) {
    int sum = 0;
    for ( int i = 0; i < financeList->size(); i++) {
        sum += financeList->at(i);
    }
    return sum;
}

int mostSpent(std::vector<int> *financeList) {
    int most = 0;
    for (int i = 0; i < financeList->size() ; i++) {
        if (financeList->at(i) > most) {
            most = financeList->at(i);
        }
    }
    return most;
}

int lessSpent(std::vector<int> *financeList) {
    int less = financeList->at(0);
    for (int i = 0; i < financeList->size() ; ++i) {
        if (financeList->at(i) < less) {
            less = financeList->at(i);
        }
    }
    return less;
}

double averageSpent(std::vector<int> *financeList) {
    double average = 0;
    average = sumSpent(financeList) / (double) financeList->size();
    return average;
}
