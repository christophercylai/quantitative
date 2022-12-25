#ifndef TERM_H
#define TERM_H


class Term
{
    public:
    explicit Term(const int& m, const int& d);
    Term getPrime();

    private:
    int degree;
    int multiplier;
};


#endif
