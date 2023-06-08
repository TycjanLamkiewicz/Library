#include "model/ClientType.h"
#include "exceptions/ParametrException.h"

ClientType::ClientType(int maxBooks, int maxRentalDays) : maxBooks(maxBooks), maxRentalDays(maxRentalDays) {
    if (maxBooks <= 0){
        throw ParametrException("Invalid maxBooks (can't be <= 0)");
    }

    if (maxRentalDays <= 0){
        throw ParametrException("Invalid maxRentalDays (can't be <= 0)");
    }
}

ClientType::~ClientType() {

}

int ClientType::getMaxBooks() const {
    return maxBooks;
}

int ClientType::getMaxRentalDays() const {
    return maxRentalDays;
}

void ClientType::setMaxBooks(int maxBooks) {
    if (maxBooks <= 0){
        throw ParametrException("Invalid maxBooks (can't be <= 0)");
    }
    else {
        ClientType::maxBooks = maxBooks;
    }
}

void ClientType::setMaxRentalDays(int maxRentalDays) {
    if (maxRentalDays <= 0){
        throw ParametrException("Invalid maxRentalDays (can't be <= 0)");
    }
    else {
        ClientType::maxRentalDays = maxRentalDays;
    }
}

float ClientType::feeCost(int days) {
    float fee = 0.0;

    if (days > this->getMaxRentalDays()){
        fee += 1.25 * (days - this->getMaxRentalDays());
    }

    return fee;
}
