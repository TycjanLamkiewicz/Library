#ifndef LIBRARYPROJECT_CLIENT_H
#define LIBRARYPROJECT_CLIENT_H


#include <string>
#include <vector>
#include "typedefs.h"
#include "model/Rent.h"
#include "model/ClientType.h"

class Client {
private:
    const int ClientID;
    std::string firstName;
    std::string lastName;
    bool isArchive;
    ClientTypePtr clientType;
    std::vector<RentPtr> currentRents;
public:
    Client(int clientId, const std::string &firstName, const std::string &lastName);

    virtual ~Client();

    /*********** getters ***********/

    const int getClientId() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    bool isArchive1() const;

    const ClientTypePtr &getClientType() const;

    const std::vector<RentPtr> &getCurrentRents() const;

    /*********** setters ***********/

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setIsArchive(bool isArchive);

    void setClientType(const ClientTypePtr &clientType);

    /************ other ************/

    std::string getClientInfo();

    std::string getFullClienxtInfo();

    void addRent(RentPtr rent);

    void removeRent(RentPtr rent);
};


#endif //LIBRARYPROJECT_CLIENT_H
