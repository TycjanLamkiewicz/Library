#ifndef LIBRARYPROJECT_UNAVAILABLEEXCEPTION_H
#define LIBRARYPROJECT_UNAVAILABLEEXCEPTION_H


#include <stdexcept>

class UnavailableException : public std::logic_error  {
public:
    explicit UnavailableException(const std::string &arg);
};


#endif //LIBRARYPROJECT_UNAVAILABLEEXCEPTION_H
