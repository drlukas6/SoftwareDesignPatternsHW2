//
// Created by Lukas Sestic on 2019-04-10.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <numeric>
#include <fstream>

#include "KeyboardSubject.h"
#include "FileSubject.h"
#include "NumberSequence.h"

void printStats(std::vector<int> &vector) {
    std::ofstream statFile("stats.txt", std::ios_base::app);
    auto sysClock = std::chrono::system_clock::now();
    auto dateTime = std::chrono::system_clock::to_time_t(sysClock);
    statFile << std::ctime(&dateTime);
    statFile << "=================================\n";
    for(auto const &number: vector) {
        statFile << number << "\n";
    }
    statFile << "---------------------------------\n";
    statFile.close();
}

void getSum(std::vector<int> &vector) {
    std::cout << "SUM: " << std::accumulate(vector.begin(), vector.end(), 0) << "\n";
}

void getAvg(std::vector<int> &vector) {
    std::cout << "AVG: " << (float) std::accumulate(vector.begin(), vector.end(), 0) / vector.size() << "\n";
}

void getMedian(std::vector<int> &vector) {
    std::sort(vector.begin(), vector.end());
    std::cout << "MED: ";
    int position = vector.size() / 2;
    if (vector.size() % 2 == 0) {
        std::cout << (vector.at(position - 1) + vector.at(position)) / 2.0;
    } else {
        std::cout << vector.at(position);
    }

    std::cout << "\n";
}

int main() {
    auto input = std::ifstream("input.txt");
    auto fileSubject = new FileSubject(input);
    auto observer = new NumberSequence(fileSubject, [](std::vector<int> &vector) -> void {
        printStats(vector);
        getSum(vector);
        getAvg(vector);
        getMedian(vector);
        std::cout << "---------------------------\n";
    });

    observer->startListening();
    return 0;
}