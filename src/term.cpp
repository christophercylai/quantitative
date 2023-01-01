// this class represents a Term in a function, such as 2x^2 in f(x)=2x^2+5x+2
#include "term.h"
#include <regex>


Term::Term(const int& m, const int& d, const char& v='?') {
    multiplier = m;
    variable = v;
    degree = d;

    std::regex var_pattern("^[a-zA-Z]");
    if (!std::regex_match(std::string(1, variable), var_pattern)) {degree = 0;}
}

Term Term::getPrime() {
    // differentiate Term
    if (degree <= 0) {
        return Term(multiplier*0, 0, variable);
    }
    return Term(multiplier*degree, degree-1, variable);
}
