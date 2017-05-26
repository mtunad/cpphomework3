class Rational {
public:
    Rational(int,int);

    int getNum();
    void setNum(int);

    int getDenom();
    void setDenom(int);

    void print();
    void printFloat();

    Rational add(const Rational & r2);
    Rational subtract(const Rational & r2);
    Rational multiply(const Rational & r2);
    Rational divide(const Rational & r2);
    
    void question(int,int,int,int,char);
private:
    int numerator;
    int denominator;
};
