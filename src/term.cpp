// this class represents a Term in a function, such as 2x^2 in f(x)=2x^2+5x+2
#include "term.h"


Term::Term(const int& m, const int& d) {
    multiplier = m;
    degree = d;
}

Term Term::getPrime() {
    // differentiate Term
    if (degree <= 0) {
        return Term(multiplier*0, 0);
    }
    return Term(multiplier*degree, degree-1);
}
