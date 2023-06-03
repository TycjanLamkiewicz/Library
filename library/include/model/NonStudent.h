#ifndef LIBRARYPROJECT_NONSTUDENT_H
#define LIBRARYPROJECT_NONSTUDENT_H


#include "ClientType.h"

class NonStudent : public ClientType {
private:
    float additionalFee;
public:
    NonStudent(int maxBooks, int maxRentalDays, float additionalFee);

    ~NonStudent() override;

    /*********** getters ***********/

    float getAdditionalFee() const;

    /*********** setters ***********/

    void setAdditionalFee(float additionalFee);

    /************ other ************/

    float feeCost(int days) override;
};


#endif //LIBRARYPROJECT_NONSTUDENT_H
