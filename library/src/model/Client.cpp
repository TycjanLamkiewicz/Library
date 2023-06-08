#include "model/Client.h"
#include "exceptions/ParametrException.h"

Client::Client(int clientId, const std::string &firstName, const std::string &lastName, const ClientTypePtr &clientType) :
                                                                                          ClientID(clientId),
                                                                                          firstName(firstName),
                                                                                          lastName(lastName),
                                                                                          clientType(clientType){
    if (firstName.empty()){
        throw ParametrException("Invalid firstName (can't be empty)");
    }

    if (lastName.empty()){
        throw ParametrException("Invalid lastName (can't be empty)");
    }

    if (clientType == nullptr){
        throw ParametrException("Invalid clientType (can't be nullptr)");
    }
}

Client::~Client() {

}

const int Client::getClientId() const {
    return ClientID;
}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

bool Client::isArchive1() const {
    return isArchive;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

int Client::getBookCount() const {
    return bookCount;
}

void Client::setFirstName(const std::string &firstName) {
    if (firstName.empty()){
        throw ParametrException("Invalid firstName (can't be empty)");
    }
    else {
        Client::firstName = firstName;
    }
}

void Client::setLastName(const std::string &lastName) {
    if (lastName.empty()){
        throw ParametrException("Invalid lastName (can't be empty)");
    }
    else {
        Client::lastName = lastName;
    }
}

void Client::setIsArchive(bool isArchive) {
    Client::isArchive = isArchive;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    if (clientType == nullptr){
        throw ParametrException("Invalid clientType (can't be nullptr)");
    }
    else {
        Client::clientType = clientType;
    }
}

void Client::setBookCount(int bookCount) {
    Client::bookCount = bookCount;
}

std::string Client::getInfo() {
    return "ID klienta: " + std::to_string(this->getClientId()) + ", imię: " + this->getFirstName() + ", nazwisko: " + this->getLastName();
}