#include <pybind11/pybind11.h>
#include "function.h"
#include "util.h"

namespace py = pybind11;


Function::Function(const std::string& f) {
    std::regex term_pattern("^([+-]?[0-9]*)([a-zA-Z]?)\\^?([0-9]*)");
    std::string func = f;
    std::smatch match;
    std::string multiplier, exponent;

    while (std::regex_search(func, match, term_pattern)) {
        multiplier = "1";
        exponent = "1";

        if (!match.str(1).empty()) {
            multiplier = match.str(1);
            func_str = func_str + match.str(1);
        }
        if (!match.str(3).empty()) {
            exponent = match.str(3);
            func_str = func_str + "^" + match.str(3);
        }
        const Term each_term(std::stoi(multiplier), std::stoi(exponent));
        polynomial.emplace_back(each_term);
        func = match.suffix().str();
        term_pattern = "([+-][0-9]*)([a-zA-Z]?)\\^?([0-9]*)";
    }

    assertTrue(!func_str.empty(), f+" is not a valid function");

    // beautification: remove plus sign at the beginning of the func_str
    const char first_char = func_str[0];
    if (first_char == '+') {
        func_str.erase(0, 1);
    }
}

const std::string& Function::getFuncStr() const {
    return func_str;
}
