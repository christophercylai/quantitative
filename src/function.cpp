// this class represents a function that consists for Terms
#include <pybind11/pybind11.h>
#include <regex>
#include "function.h"
#include "util.h"


Function::Function(const std::string& f) {
    std::regex term_pattern("^([+-])?([0-9]*)([a-zA-Z]?)(\\^)?(-?[0-9]*)");
    std::string func = f;
    std::smatch match;
    std::string multiplier, exponent;
    char sign, variable;
    int multiplier_num;
    bool term_exists = false;

    while (std::regex_search(func, match, term_pattern)) {
        sign = '+';
        multiplier = "1";
        exponent = "0";
        variable = '?';

        // handling regex groups
        if (!match.str(1).empty()) {
            sign = match.str(1).front();
        }
        if (!match.str(2).empty()) {
            term_exists = true;
            multiplier = match.str(2);
        }
        if (!match.str(3).empty()) {
            term_exists = true;
            exponent = "1";
            variable = match.str(3).front();
        }
        if (!match.str(4).empty() && !match.str(5).empty()) {
            exponent = match.str(5);
        }

        multiplier_num = std::stoi(multiplier);
        if (sign == '-') {
            multiplier_num *= -1;
        }
        const Term each_term(multiplier_num, std::stoi(exponent), variable);
        polynomial.emplace_back(each_term);

        if (!match.str(4).empty()) {
            func = match.suffix().str();
        } else {
            // if ^ does not exists, add the 5th regex group back to the remaining of func
            func = match.str(5) + match.suffix().str();
        }

        // term_pattern for the 2nd term and onward
        term_pattern = "([+-])([0-9]*)([a-zA-Z]?)(\\^)?(-?[0-9]*)";
    }
    assertTrue(term_exists, f+" is not a valid function");
    sortPolynomial();
    polynomial.shrink_to_fit();
}

void Function::sortPolynomial() {
    std::vector<Term> sorted_poly;
    sorted_poly.emplace_back(polynomial.front());
    std::vector<Term>::iterator s_iter;
    bool emplaced, replace;

    for (auto p = polynomial.begin()+1; p != polynomial.end(); p++) {
        emplaced = false;
        replace = false;
        for (auto s = sorted_poly.begin(); s != sorted_poly.end(); s++) {
            if ((*p).degree > (*s).degree) {
                emplaced = true;
                if (s == sorted_poly.begin()) {
                    // this avoids s_iter from becoming -1
                    s_iter = s;
                } else {
                    s_iter = s-1;
                }
                continue;
            }
            if ((*p).degree == (*s).degree && (*p).variable == (*s).variable) {
                replace = true;
                s_iter = s;
                continue;
            }
        }
        if (replace) {
            sorted_poly.at(std::distance(sorted_poly.begin(), s_iter)) = (*p).addTerm(*s_iter);
            continue;
        }
        if (emplaced) {
            sorted_poly.emplace(s_iter, *p);
        } else {
            sorted_poly.emplace_back(*p);
        }
    }
    polynomial = sorted_poly;
}

const std::string& Function::getFuncStr(const bool& verbose=false) {
    func_str = "";
    for (Term t : polynomial) {
        func_str += t.getTermStr(verbose) + " ";
    }

    // beautification
    func_str.pop_back();
    const char first_char = func_str[0];
    if (first_char == '+') {
        // remove plus sign at the beginning of the func_str
        func_str.erase(0, 1);
    }

    return func_str;
}
