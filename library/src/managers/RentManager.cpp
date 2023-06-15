#include "managers/RentManager.h"
#include "model/Repository.h"
#include "model/Rent.h"
#include "model/Client.h"
#include <boost/uuid/uuid_generators.hpp>
#include "exceptions/ParametrException.h"


RentManager::RentManager(const RentRepositoryPtr &currentRents, const RentRepositoryPtr &archiveRents) : currentRents(
        currentRents), archiveRents(archiveRents) {}

RentManager::~RentManager() {}


RentPtr RentManager::rentBook(const ClientPtr &client, const BookPtr &book) {

    if (getRent(book) == nullptr) {
        int randomID = idGenerator.generateRandomID();
        RentPtr newRent = std::make_shared<Rent>(randomID, client, book);
        currentRents->add(newRent);
        return newRent;
    } else {
        return nullptr;
    }
}

void RentManager::returnBook(const BookPtr &book) const {

    RentPtr rent = getRent(book);

    if (rent != nullptr) {
        rent->endRent();
        archiveRents->add(rent);
        currentRents->remove(rent);
    }
}

RentPtr RentManager::getRent(const BookPtr &book) const {
    RentPredicate predicate = [book](const RentPtr ptr) {

        return ptr->getBook() == book;
    };
    return currentRents->find(predicate);
}

std::string RentManager::getAllCurrentRentsReports() const {
    return currentRents->report();
}

std::string RentManager::getAllArchiveRentsReports() const {
    return archiveRents->report();
}

