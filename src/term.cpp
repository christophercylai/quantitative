// this class represents a Term in a function, such as 2x^2 in f(x)=2x^2+5x+2
#include "term.h"


Term::Term(const int& m, const int& d, const char& v='?') {
    multiplier = m;
    variable = v;
    degree = d;
}

const std::string Term::getTermStr(const bool& verbose=false) const{
    std::string term_str = "";
    if (verbose) {
        // prints out everything for debugging
        if (multiplier > 0) {term_str += "+";}
        term_str += std::to_string(multiplier) + std::string(1, variable) + "^" + std::to_string(degree);
        return term_str;
    }

    if (multiplier == 0) {
        term_str = "0";
        return term_str;
    }

    if (multiplier > 0) {term_str += "+";}
    term_str += std::to_string(multiplier);
    if (degree == 0) {
        return term_str;
    }

    // +mx to +x || -mx = -x
    if (multiplier == 1 || multiplier == -1) {
        term_str.pop_back();
    }

    if (degree == 1) {
        term_str += std::string(1, variable);
        return term_str;
    }
    term_str += (std::string(1, variable) + "^" + std::to_string(degree));

    return term_str;
}

Term Term::getPrime() {
    // differentiate Term
    if (degree <= 0) {
        return Term(multiplier*0, 0, variable);
    }
    return Term(multiplier*degree, degree-1, variable);
}
