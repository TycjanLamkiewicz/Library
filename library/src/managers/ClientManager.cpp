#include "managers/ClientManager.h"
#include "model/Repository.h"
#include "model/Client.h"
#include "exceptions/ParametrException.h"

ClientManager::ClientManager(const ClientRepositoryPtr &clientRepository) : clientRepository(clientRepository) {}

ClientManager::~ClientManager() {}

ClientPtr ClientManager::registerClient(std::string &firstName, std::string &lastName, int clientID, const ClientTypePtr &clientType) {

    ClientPtr clientCheck = getClient(clientID);
    if (clientCheck == nullptr) {
        ClientPtr newClient = std::make_shared<Client>(clientID, firstName, lastName, clientType);
        clientRepository->add(newClient);
        return newClient;
    } else {
        clientCheck->setIsArchive(false);
        clientCheck->setFirstName(firstName);
        clientCheck->setLastName(lastName);
        clientCheck->setClientType(clientType);
        return clientCheck;
    }
}

void ClientManager::unregisterClient(const ClientPtr &client) {
    if (client == nullptr) {
        throw ParametrException("Wrong input");
    }
    client->setIsArchive(true);
}

ClientPtr ClientManager::getClient(int clientID) const {
    ClientPredicate predicate = [clientID](const ClientPtr ptr) {
        return ptr->getClientId() == clientID;
    };
    return clientRepository->find(predicate);
}

std::string ClientManager::getAllClientsReports() const {
    return clientRepository->report();
}
