#include <iostream>

class complex {
public:
    explicit complex(double rn=0.0, double im=0.0)
    : r{rn}, i{im}
    { }

//    complex operator+( const complex& c2) const {
//        return complex(r + c2.r, i + c2.i);
//    }

    complex operator+( double r2) const {
        return complex(r + r2, i);
    }
//    complex operator-() const {
//        return complex(-r, -i);
//    }
    double real() const {
        return r;
    }
    double imag() const {
        return i;
    }
private:
    double r, i;
};

double real(const complex& c) {
    return c.real();
}

double imag(const complex& c) {
    return c.imag();
}

inline complex operator+( double d, const complex& c2) {
    return complex(d + real(c2), imag(c2));
}

inline complex operator+( const complex& c1, const complex& c2) {
    return complex(real(c1) + real(c2), imag(c1) + imag(c2));
}

complex operator-(const complex& c1) {
    return complex(-real(c1), -imag(c1));
}

int main() {
    complex cc{7.0, 8.0}, c4{cc};
    std::cout << "cc + c4 is " << real(cc + c4) << ", " << imag(cc + c4) << std::endl;
    std::cout << "cc + 4.2 is " << real(cc + 4.2) << ", " << imag(cc + 4.2) << std::endl;
    std::cout << "4.2 + c4 is " << real(4.2 + c4) << ", " << imag(4.2 + c4) << std::endl;
    std::cout << "-c4 is " << real(-c4) << std::endl;
    // 4.2.operator+(c4)
}
