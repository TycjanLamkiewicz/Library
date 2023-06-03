#include "model/Author.h"

Author::Author(int authorId, const std::string &name, const std::string &surname) : authorID(authorId), name(name),
                                                                                    surname(surname) {}

Author::~Author() {

}

int Author::getAuthorId() const {
    return authorID;
}

const std::string &Author::getName() const {
    return name;
}

const std::string &Author::getSurname() const {
    return surname;
}

void Author::setName(const std::string &name) {
    if (name != ""){
        Author::name = name;
    }
}

void Author::setSurname(const std::string &surname) {
    if (surname != ""){
        Author::surname = surname;
    }
}

std::string Author::getAuthorInfo() {
    return "imię: " + getName() + ", nazwikso: " + getSurname();
}
