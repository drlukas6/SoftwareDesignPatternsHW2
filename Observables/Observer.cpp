//
// Created by Lukas Sestic on 2019-04-10.
//

#include "Observer.h"
#include "Subject.h"

Observer::Observer(Subject *subject) {
    this->subject = subject;
    subject->attach(this);
}

Subject Observer::getSubject() {
    return Subject();
}
