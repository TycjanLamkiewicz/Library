#include "model/Client.h"

Client::Client(int clientId, const std::string &firstName, const std::string &lastName) : ClientID(clientId),
                                                                                          firstName(firstName),
                                                                                          lastName(lastName) {}

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

const std::vector<RentPtr> &Client::getCurrentRents() const {
    return currentRents;
}

void Client::setFirstName(const std::string &firstName) {
    if (firstName != ""){
        Client::firstName = firstName;
    }
}

void Client::setLastName(const std::string &lastName) {
    if (lastName != ""){
        Client::lastName = lastName;
    }
}

void Client::setIsArchive(bool isArchive) {
    Client::isArchive = isArchive;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    Client::clientType = clientType;
}

std::string Client::getClientInfo() {
    return "ID klienta: " + std::to_string(this->getClientId()) + ", imię: " + this->getFirstName() + ", nazwisko: " + this->getLastName();
}

std::string Client::getFullClienxtInfo() {
    std::string info = "";

    info += this->getClientInfo();
    info += "\n";

    for (int i = 0; i < currentRents.size(); i++){
        info += currentRents[i]->getRentInfo();
        info += "\n";
    }

    return info;
}

void Client::addRent(RentPtr rent) {
    if (rent != nullptr){
        currentRents.push_back(rent);
    }
}

void Client::removeRent(RentPtr rent) {
    currentRents.erase(std::remove(currentRents.begin(), currentRents.end(), rent), currentRents.end());
}
