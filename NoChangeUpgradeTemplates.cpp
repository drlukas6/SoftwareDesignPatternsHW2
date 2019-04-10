//
// Created by Lukas Sestic on 2019-04-09.
//

#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iterator, typename Predicate>
Iterator mymax(Iterator cur, Iterator last, Predicate pred){

    Iterator currentMax = cur;

    while (cur != last) {
        if (pred(*cur, *currentMax)) currentMax = cur;
        cur++;
    }

    return currentMax;
}

template<typename T>
bool isGreaterThan(T &lhs, T &rhs) {
    return lhs > rhs;
}

int main() {
    std::vector<int> numbers = {1, 1, 99, 49, 2};
    std::cout << "Max INT int VECTOR: " << *mymax(numbers.begin(), numbers.end(), isGreaterThan<int>) << "\n";

    std::vector<float> floats = {1.4, 99.22, 112.949, 2.4};
    std::cout << "Max FLOAT int VECTOR: " << *mymax(floats.begin(), floats.end(), isGreaterThan<float>) << "\n";

    std::vector<std::string> strings = {"Lukas", "Njemacka", "Azerbejdan", "A"};
    std::cout << "Max FLOAT int VECTOR: " << *mymax(strings.begin(), strings.end(), isGreaterThan<std::string>) << "\n";

    return 0;
}