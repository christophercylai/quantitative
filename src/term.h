#ifndef TERM_H
#define TERM_H

#include <string>


class Term
{
    public:
    int multiplier;
    int degree;
    char variable;

    explicit Term(const int& m, const int& d, const char& v);
    const std::string getTermStr(const bool& verbose) const;
    Term getPrime();
};


#endif
