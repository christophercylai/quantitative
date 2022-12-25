#include <pybind11/pybind11.h>
#include "function.h"
#include "util.h"

namespace py = pybind11;


Function::Function(const std::string& f) {
    std::smatch match;
    const std::regex get_term("^[+-]?[0-9]*[A-Za-z]{1}[^]?[0-9]*");
    //const std::regex get_multiplier("^[+-]?[0-9]");
    //const std::regex get_exponent("[^]+[0-9]+");
    std::regex_search(f, match, get_term);
    for (std::string m : match) {
        func = m;
    }
    assertTrue(!func.empty(), f+" is not a valid function");
}

const std::string& Function::printFunc() const {
    return func;
}
