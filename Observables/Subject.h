//
// Created by Lukas Sestic on 2019-04-10.
//

#ifndef INC_2__LAB_SUBJECT_H
#define INC_2__LAB_SUBJECT_H

#include <vector>

class Observer;

class Subject {
private:
    std::vector<Observer *> observers;
    int value;
public:
    void attach(Observer *observer);
    void broadcast();
    int getValue();
    void setValue(int value);

    virtual void startReading() =0;
};

#endif //INC_2__LAB_SUBJECT_H
