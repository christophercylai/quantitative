class Term
{
    public:
        explicit Term(int d, int m);
        int degree;
        int multiplier;
        Term getPrime();
};

int add(int i, int j);
