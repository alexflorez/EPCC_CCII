#include "rational.h"
#include <numeric>

Rational::Rational()
: Rational{0}
{}

Rational::Rational(int num)
: Rational{num,1}
{}

Rational::Rational(int num, int den)
: numerator_{num}, denominator_{den}
{
    reduce();
}

void Rational::assign(int num, int den) {
    numerator_ = num;
    denominator_ = den;
    reduce();
}

void Rational::reduce() {
    // comprobar que denominador sea distinto de cero
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    int div{std::gcd(numerator_, denominator_)};
    numerator_ = numerator_ / div;
    denominator_ = denominator_ / div;
}

int Rational::numerator() const {
    return numerator_;
}

int Rational::denominator() const {
    return denominator_;
}

Rational& Rational::operator=(int num) {
    numerator_ = num;
    denominator_ = 1;
    return *this;
}
