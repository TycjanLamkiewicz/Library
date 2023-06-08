#include "exceptions/ParametrException.h"

ParametrException::ParametrException(const std::string &arg) : logic_error(arg) {}
