#ifndef LIBRARYPROJECT_PARAMETREXCEPTION_H
#define LIBRARYPROJECT_PARAMETREXCEPTION_H

#include <stdexcept>

class ParametrException : public std::logic_error {
public:
    explicit ParametrException(const std::string &arg);
};


#endif //LIBRARYPROJECT_PARAMETREXCEPTION_H
