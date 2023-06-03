#include "model/Rent.h"

Rent::Rent(int rentId, const ClientPtr &client, const BookPtr &book) : rentID(rentId), client(client), book(book) {
    client->addRent(shared_from_this());
    book->setRented(true);
    if (beginDate.is_not_a_date()){
        beginDate = gr::day_clock::local_day();
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
    Rent::endDate = endDate;
}

void Rent::setFee(float fee) {
    Rent::fee = fee;
}

std::string Rent::getRentInfo() {
    return "ID: " + std::to_string(this->getRentId()) + ", data rozpoczęcia: " + boost::gregorian::to_simple_string(this->getBeginDate()) + "data zakończenia: " + boost::gregorian::to_simple_string(
            this->getEndDate()) + ", opłata: " + std::to_string(this->getFee()) + ", klient: " + this->getClient()->getClientInfo() + ", książka: " + this->getBook()->getBookInfo();
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
    client->removeRent(shared_from_this());

    float fee = this->getClient()->getClientType()->feeCost(this->getRentDays());
    this->setFee(fee);
}
