//
// Created by Lukas Sestic on 2019-04-10.
//

#ifndef INC_2__LAB_NUMBERSEQUENCE_H
#define INC_2__LAB_NUMBERSEQUENCE_H

#include <vector>
#include <functional>

#include "Observer.h"
#include "Subject.h"

typedef void (*ActivationFunction)(std::vector<int>&);

class NumberSequence: public Observer {
private:
    std::vector<int> _sequence;
    ActivationFunction _activationFunction;
public:
    explicit NumberSequence(Subject *subject, ActivationFunction activationFunction) {
        this->subject = subject;
        this->subject->attach(this);
        this->_activationFunction = activationFunction;
    }
    void update() override;
};


#endif //INC_2__LAB_NUMBERSEQUENCE_H
