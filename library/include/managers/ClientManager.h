
#ifndef LIBRARYPROJECT_CLIENTMANAGER_H
#define LIBRARYPROJECT_CLIENTMANAGER_H

#include "typedefs.h"


class ClientManager {
private:
    ClientRepositoryPtr clientRepository;
public:
    explicit ClientManager(const ClientRepositoryPtr &clientRepository);
    virtual ~ClientManager();

    ClientPtr registerClient(std::string &firstName, std::string &lastName, int ClientID, const ClientTypePtr &clientType);
    void unregisterClient(const ClientPtr &client);
    ClientPtr getClient(int ClientID) const;
    std::string getAllClientsReports() const;

};


#endif //LIBRARYPROJECT_CLIENTMANAGER_H
