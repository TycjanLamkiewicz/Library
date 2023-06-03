#include "model/Book.h"

Book::Book(int id, const std::string &title, const AuthorPtr &author) : id(id), title(title), author(author) {}

Book::~Book() {

}

const int Book::getId() const {
    return id;
}

const std::string &Book::getTitle() const {
    return title;
}

bool Book::isRented() const {
    return rented;
}

bool Book::isArchive1() const {
    return isArchive;
}

const AuthorPtr &Book::getAuthor() const {
    return author;
}

void Book::setTitle(const std::string &title) {
    if (title != ""){
        Book::title = title;
    }
}

void Book::setRented(bool rented) {
    Book::rented = rented;
}

void Book::setIsArchive(bool isArchive) {
    Book::isArchive = isArchive;
}

std::string Book::getBookInfo() {
    return "ID; " + std::to_string(this->getId()) + ", tytuł: " + this->getTitle() + ", wypożyczona: " + std::to_string(this->isRented()) + ", zarchiwizowana: " + std::to_string(this->isArchive1())  + ", autor: " +this->getAuthor()->getAuthorInfo();
}
