#include "model/Author.h"
#include "exceptions/ParametrException.h"

Author::Author(int authorId, const std::string &name, const std::string &surname) : authorID(authorId), name(name),
                                                                                    surname(surname) {
    if (name.empty()){
        throw ParametrException("Invalid name (can't be empty)");
    }

    if (surname.empty()){
        throw ParametrException("Invalid surname (can't be empty)");
    }
}

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
    if (name.empty()){
        throw ParametrException("Invalid name (can't be empty)");
    }
    else {
        Author::name = name;
    }
}

void Author::setSurname(const std::string &surname) {
    if (surname.empty()){
        throw ParametrException("Invalid surname (can't be empty)");
    }
    else {
        Author::surname = surname;
    }
}

std::string Author::getAuthorInfo() {
    return "imię: " + getName() + ", nazwikso: " + getSurname();
}
