#ifndef TERM_H
#define TERM_H

#include <string>


class Term
{
    public:
    explicit Term(const int& m, const int& d, const char& v);
    const std::string getTermStr() const;
    Term getPrime();

    private:
    int degree;
    int multiplier;
    char variable;
};


#endif
