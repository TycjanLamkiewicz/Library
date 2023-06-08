#include "model/NonStudent.h"
#include "exceptions/ParametrException.h"

NonStudent::NonStudent(int maxBooks, int maxRentalDays, float additionalFee) : ClientType(maxBooks, maxRentalDays),
                                                                               additionalFee(additionalFee) {
    if (additionalFee <= 0){
        throw ParametrException("Invalid additionalFee (can't be <= 0)");
    }
}

NonStudent::~NonStudent() {

}

float NonStudent::getAdditionalFee() const {
    return additionalFee;
}

void NonStudent::setAdditionalFee(float additionalFee) {
    if (additionalFee <= 0){
        throw ParametrException("Invalid additionalFee (can't be <= 0)");
    }
    else {
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
