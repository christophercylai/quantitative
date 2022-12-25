#include <pybind11/pybind11.h>
#include "function.h"
#include "util.h"

namespace py = pybind11;


Function::Function(const std::string& f) {
    std::string func = f;
    std::smatch match;
    std::regex term_pattern("([-]?[0-9]*[a-zA-Z]\\^?[0-9]*)");
    while (std::regex_search(func, match, term_pattern)) {
        polynomial.emplace_back(match.str(0));
        func_str = func_str + match.str(0);
        func = match.suffix().str();
        term_pattern = "([+-][0-9]*[a-zA-Z]\\^?[0-9]*)";
    }
    for (auto s : polynomial) {
        printMsg(s);
    }
    assertTrue(!func_str.empty(), f+" is not a valid function");
}

const std::string& Function::printFunc() const {
    return func_str;
}
