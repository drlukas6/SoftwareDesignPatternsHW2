//
// Created by Lukas Sestic on 2019-04-10.
//

#ifndef INC_2__LAB_OBSERVER_H
#define INC_2__LAB_OBSERVER_H

class Subject;

class Observer {
private:
    Subject *subject;
public:
    explicit Observer (Subject *subject);
    virtual void update() =0;
protected:
    Subject getSubject();
};

#endif //INC_2__LAB_OBSERVER_H
