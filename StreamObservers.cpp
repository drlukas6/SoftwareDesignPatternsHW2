//
// Created by Lukas Sestic on 2019-04-10.
//

#include <iostream>
#include "Subject.h"
#include "Observer.h"

class Test: public Observer {
public:
    Test (Subject *subject) : Observer(subject) {

    }
    void update() override {
        printf("dlčkfjaskfdsa");
    }
};

int main() {
    Test t(NULL);

    return 0;
}