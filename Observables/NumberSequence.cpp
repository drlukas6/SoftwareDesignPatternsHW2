//
// Created by Lukas Sestic on 2019-04-10.
//

#include <iostream>
#include "NumberSequence.h"
#include "Subject.h"

void NumberSequence::update() {
    this->_sequence.emplace_back(this->getSubject()->getValue());
    _activationFunction(_sequence);
}
