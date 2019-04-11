//
// Created by Lukas Sestic on 2019-04-10.
//

#include <vector>

#include "Subject.h"
#include "Observer.h"

void Subject::attach(Observer *observer) {
    this->observers.emplace_back(observer);
}

void Subject::broadcast() {
    for(auto const &observer : this->observers) {
        observer->update();
    }
}

int Subject::getValue() {
    return value;
}

void Subject::setValue(int value) {
    this->value = value;
    this->broadcast();
}
