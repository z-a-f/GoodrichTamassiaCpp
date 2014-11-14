#ifndef RUNTIME_EXCEPTIONS_HPP
#define RUNTIME_EXCEPTIONS_HPP

#include <string>

/****************************************************************
 * Exceptions
 ****************************************************************/
class RuntimeException {
private:
  std::string errorMsg;
public:
  RuntimeException(const std::string& err) { errorMsg = err; }
  std::string getMessage() const { return errorMsg; }
};

class TreeNotEmptyException : public RuntimeException {
public:
  TreeNotEmptyException(const std::string& err = "Tree is not empty!")
    : RuntimeException(err) {}
};

#endif
