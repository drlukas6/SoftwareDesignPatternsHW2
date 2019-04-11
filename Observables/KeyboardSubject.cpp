//
// Created by Lukas Sestic on 2019-04-11.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "KeyboardSubject.h"

void KeyboardSubject::startReading() {
    int number;
    while (true) {
        std::cout << "Enter number: ";
        std::cin >> number;
        if (number < 0) break;
        this->setValue(number);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
