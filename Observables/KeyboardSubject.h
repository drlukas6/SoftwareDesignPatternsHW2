//
// Created by Lukas Sestic on 2019-04-11.
//

#ifndef INC_2__LAB_KEYBOARDSUBJECT_H
#define INC_2__LAB_KEYBOARDSUBJECT_H

#include "Subject.h"

class KeyboardSubject: public Subject {
public:
    void startReading() override;
};


#endif //INC_2__LAB_KEYBOARDSUBJECT_H
