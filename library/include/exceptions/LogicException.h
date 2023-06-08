#ifndef LIBRARYPROJECT_LOGICEXCEPTION_H
#define LIBRARYPROJECT_LOGICEXCEPTION_H

#include <stdexcept>

class LogicException : public std::logic_error {
public:
    explicit LogicException(const std::string& what_arg);
};


#endif //LIBRARYPROJECT_LOGICEXCEPTION_H
