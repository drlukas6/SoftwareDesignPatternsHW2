//
// Created by Lukas Sestic on 2019-04-10.
//

#ifndef INC_2__LAB_OBSERVER_H
#define INC_2__LAB_OBSERVER_H

class Subject;

class Observer {
protected:
    Subject *subject;
public:
    Subject *getSubject();
    void startListening();
    virtual void update() =0;
};

#endif //INC_2__LAB_OBSERVER_H