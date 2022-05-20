#ifndef PROGRAMMING_RATIONAL_H
#define PROGRAMMING_RATIONAL_H


class Rational {
public:
    Rational();
    Rational(int num, int den);
    Rational(int num);
    void assign(int num, int den);
    int numerator() const;
    int denominator() const;
    Rational& operator=(int num);
private:
    void reduce();
    int numerator_;
    int denominator_;
};

#endif //PROGRAMMING_RATIONAL_H
