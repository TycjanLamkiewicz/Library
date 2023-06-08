#include "exceptions/LogicException.h"

LogicException::LogicException(const std::string &what_arg) : std::logic_error(what_arg) {}
