#include "model/NonStudent.h"

NonStudent::NonStudent(int maxBooks, int maxRentalDays, float additionalFee) : ClientType(maxBooks, maxRentalDays),
                                                                               additionalFee(additionalFee) {}

NonStudent::~NonStudent() {

}

float NonStudent::getAdditionalFee() const {
    return additionalFee;
}

void NonStudent::setAdditionalFee(float additionalFee) {
    if (additionalFee > 0){
        NonStudent::additionalFee = additionalFee;
    }
}

float NonStudent::feeCost(int days) {
    if (days > this->getMaxRentalDays()){
        return ClientType::feeCost(days) + this->getAdditionalFee();
    }
    else {
        return ClientType::feeCost(days);
    }
}
