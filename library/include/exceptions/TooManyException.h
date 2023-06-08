#ifndef LIBRARYPROJECT_TOOMANYEXCEPTION_H
#define LIBRARYPROJECT_TOOMANYEXCEPTION_H


#include <stdexcept>

class TooManyException : public std::logic_error  {
public:
    explicit TooManyException(const std::string &arg);
};


#endif //LIBRARYPROJECT_TOOMANYEXCEPTION_H
