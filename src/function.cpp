// this class represents a Term in a function, such as 2x^2 in f(x)=2x^2+5x+2 
class Term
{
    public:
        explicit Term(int d, int m) {
            degree = d;
            multiplier = m;
        }
        int degree;
        int multiplier;

        Term getPrime() {
            // differentiate Term
            if (degree <= 0) {
                return Term(0, multiplier*0);
            }
            return Term(degree-1, multiplier*degree);
        }
};

int add(int i, int j) {
    return i + j;
}