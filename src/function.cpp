// this class represents a function that consists for Terms
#include <pybind11/pybind11.h>
#include <regex>
#include "function.h"
#include "util.h"


Function::Function(const std::string& f) {
    std::regex term_pattern("^([+-]?[0-9]*)([a-zA-Z]?)\\^?([0-9]*)");
    std::string func = f;
    std::smatch match;
    std::string multiplier, exponent;
    char variable;

    while (std::regex_search(func, match, term_pattern)) {
        multiplier = "1";
        exponent = "0";
        variable = '?';

        // handling regex groups
        if (!match.str(1).empty()) {
            multiplier = match.str(1);
        }
        if (!match.str(2).empty()) {
            exponent = "1";
            variable = match.str(2)[0];
            if (!match.str(3).empty()) {
                exponent = match.str(3);
            }
        }

        const Term each_term(std::stoi(multiplier), std::stoi(exponent), variable);
        polynomial.emplace_back(each_term);
        func = match.suffix().str();
        term_pattern = "([+-][0-9]*)([a-zA-Z]?)\\^?([0-9]*)";
    }

    assertTrue(!polynomial.empty(), f+" is not a valid function");
}

const std::string& Function::getFuncStr() {
    for (Term t : polynomial) {
        func_str += t.getTermStr();
    }

    // beautification: remove plus sign at the beginning of the func_str
    const char first_char = func_str[0];
    if (first_char == '+') {
        func_str.erase(0, 1);
    }

    return func_str;
}
