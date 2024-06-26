#ifndef LIBRARYPROJECT_STUDENT_H
#define LIBRARYPROJECT_STUDENT_H


#include "ClientType.h"

class Student : public ClientType {
public:
    Student(int maxBooks, int maxRentalDays);

    virtual ~Student();

    /************ other ************/

    float feeCost(int days) override;
};


#endif //LIBRARYPROJECT_STUDENT_H
