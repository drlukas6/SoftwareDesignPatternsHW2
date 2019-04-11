//
// Created by Lukas Sestic on 2019-04-11.
//

#include <thread>
#include <chrono>

#include "FileSubject.h"

FileSubject::FileSubject(std::ifstream &fileStream) {
    this->_fileStream = &fileStream;
}

void FileSubject::startReading() {
    int value;
    while(*_fileStream >> value) {
        if (value == -1) break;
        this->setValue(value);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
