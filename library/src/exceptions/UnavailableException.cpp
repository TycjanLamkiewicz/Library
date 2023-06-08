#include "exceptions/UnavailableException.h"

UnavailableException::UnavailableException(const std::string &arg) : logic_error(arg) {}
