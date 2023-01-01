#ifndef TERM_H
#define TERM_H


class Term
{
    public:
    explicit Term(const int& m, const int& d, const char& v);
    Term getPrime();

    private:
    int degree;
    int multiplier;
    char variable;
};


#endif
