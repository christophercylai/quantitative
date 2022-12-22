#include <string>
#include "function.h"

Function::Function(const std::string f) : func(f) {}
const std::string& Function::printFunc() const {
    return func;
}
