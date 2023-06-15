#ifndef LIBRARYPROJECT_RENTMANAGER_H
#define LIBRARYPROJECT_RENTMANAGER_H

#include "typedefs.h"
#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>
#include "model/IdGenerator.h"

class RentManager {
private:
    RentRepositoryPtr currentRents;
    RentRepositoryPtr archiveRents;
    IdGenerator idGenerator;
public:
    RentManager(const RentRepositoryPtr &currentRents, const RentRepositoryPtr &archiveRents);
    virtual ~RentManager();

    RentPtr rentBook(const ClientPtr &client, const BookPtr &book);
    void returnBook(const BookPtr& book) const;
    RentPtr getRent(const BookPtr &book) const;
    std::string getAllCurrentRentsReports() const;
    std::string getAllArchiveRentsReports() const;

};


#endif //LIBRARYPROJECT_RENTMANAGER_H
