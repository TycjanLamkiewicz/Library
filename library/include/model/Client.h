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
    int bookCount = 0;
public:
    Client(int clientId, const std::string &firstName, const std::string &lastName, const ClientTypePtr &clientType);

    virtual ~Client();

    /*********** getters ***********/

    const int getClientId() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    bool isArchive1() const;

    const ClientTypePtr &getClientType() const;

    int getBookCount() const;

    /*********** setters ***********/

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setIsArchive(bool isArchive);

    void setClientType(const ClientTypePtr &clientType);

    void setBookCount(int bookCount);

    /************ other ************/

    std::string getInfo();
};


#endif //LIBRARYPROJECT_CLIENT_H
