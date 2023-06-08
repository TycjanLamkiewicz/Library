#include "model/Rent.h"
#include "exceptions/ParametrException.h"
#include "exceptions/TooManyException.h"
#include "exceptions/UnavailableException.h"

Rent::Rent(int rentId, const ClientPtr &client, const BookPtr &book) : rentID(rentId), client(client), book(book) {
    if (client == nullptr){
        throw ParametrException("Invalid client (can't be nullptr)");
    }
    else if (book == nullptr){
        throw ParametrException("Invalid book (can't be nullptr)");
    }
    else if (client->getBookCount() >= client->getClientType()->getMaxBooks()){
        throw TooManyException("Client can't have more rents than maxBooks");
    }
    else if (client->isArchive1() == true){
        throw UnavailableException("Client is unavailable");
    }
    else if (book->isRented() == true || book->isArchive1() == true){
        throw UnavailableException("Book is unavailable");
    }
    else {
        client->setBookCount(client->getBookCount()+1);
        book->setRented(true);
        if (beginDate.is_not_a_date()){
            beginDate = gr::day_clock::local_day();
        }
    }
}

Rent::~Rent() {

}

int Rent::getRentId() const {
    return rentID;
}

const gr::date &Rent::getBeginDate() const {
    return beginDate;
}

const gr::date &Rent::getEndDate() const {
    return endDate;
}

float Rent::getFee() const {
    return fee;
}

const ClientPtr &Rent::getClient() const {
    return client;
}

const BookPtr &Rent::getBook() const {
    return book;
}

void Rent::setEndDate(const gr::date &endDate) {
    if (endDate < beginDate){
        throw ParametrException("Invalid endDate (can't be < beginDate)");
    }
    else {
        Rent::endDate = endDate;
    }
}

void Rent::setFee(float fee) {
    if (fee < 0){
        throw ParametrException("Invalid fee (can't be < 0)");
    }
    else {
        Rent::fee = fee;
    }
}

std::string Rent::getInfo() {
    return "ID: " + std::to_string(this->getRentId()) + ", data rozpoczęcia: " + boost::gregorian::to_simple_string(this->getBeginDate()) + "data zakończenia: " + boost::gregorian::to_simple_string(
            this->getEndDate()) + ", opłata: " + std::to_string(this->getFee()) + ", klient: " +
            this->getClient()->getInfo() + ", książka: " + this->getBook()->getInfo();
}

int Rent::getRentDays() {
    int days;

    gr::date_period period(beginDate, endDate);

    if (endDate.is_not_a_date()){
        days = 0;
    }
    else{
        days = period.length().days();
    }

    return days;
}

void Rent::endRent() {
    if (endDate.is_not_a_date()){
        if (beginDate < endDate){
            this->setEndDate(gr::day_clock::local_day());
        }
        else {
            this->setEndDate(beginDate);
        }
    }

    book->setRented(false);

    float fee = this->getClient()->getClientType()->feeCost(this->getRentDays());
    this->setFee(fee);
}
