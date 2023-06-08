#include "exceptions/TooManyException.h"

TooManyException::TooManyException(const std::string &arg) : logic_error(arg) {}
