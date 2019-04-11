//
// Created by Lukas Sestic on 2019-04-11.
//

#ifndef INC_2__LAB_FILESUBJECT_H
#define INC_2__LAB_FILESUBJECT_H

#include <fstream>
#include "Subject.h"

class FileSubject: public Subject {
private:
    std::ifstream *_fileStream;
public:
    explicit FileSubject (std::ifstream &fileStream);
    void startReading() override;
};


#endif //INC_2__LAB_FILESUBJECT_H
