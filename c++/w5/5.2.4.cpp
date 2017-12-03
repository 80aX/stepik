// Определите для класса Rational операторы сложения, вычитания, умножения и деления, 
// так чтобы объекты типа Rational можно было складывать (вычитать, умножать и делить) 
// не только друг с другом но и с целыми числами.

// Требования к реализации: ваш код не должен вводить или выводить что-либо, реализовывать 
// функцию main не нужно.


#include <iostream>


struct Rational
{
    private:
        int numerator_;
        int denominator_;
    
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;
};


Rational operator+(Rational lhs, Rational rhs) {
    lhs += rhs;
    return lhs;
}

Rational operator-(Rational lhs, Rational rhs) {
    lhs -= rhs;
    return lhs;
}

Rational operator*(Rational lhs, Rational rhs) {
    lhs *= rhs;
    return lhs;
}

Rational operator/(Rational lhs, Rational rhs) {
    lhs /= rhs;
    return lhs;
}


int main()
{
    Rational example;
    example + 5;
    std::cout << example.numerator_ << std::endl;
    std::cout << example.denominator_ << std::endl;
    
    return 0;
}
