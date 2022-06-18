#include <iostream>

class complex {
public:
    explicit complex(double rn=0.0, double im=0.0)
    : r{rn}, i{im}
    { }
    complex operator-() const {
        return complex(-r, -i);
    }
    double real() const {
        return r;
    }
    double imag() const {
        return i;
    }
    void asignar(const double rn=0.0, const double im=0.0) {
        r = rn;
        i = im;
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

std::ostream& operator<<(std::ostream& os, const complex& c) {
    return os << "(" << real(c) << ", " << imag(c) << ")";
}

// a, b
std::istream& operator>>(std::istream& is, complex& c) {
    std::cout << "Ingrese un complejo en el formato: real , imag" << std::endl;
    double re{0}, im{0};
    char sep{'\0'};
    if (not (is >> re >> sep))
        // Error al leer el real o el caracter de separacion
        is.setstate(std::ios::failbit);
    else if (sep != ',') {
        // Se leyó la parte real, pero no le sigue una coma
        // Colocamos de vuelta sep en el stream
        is.unget();
        c.asignar(re);
    } else if (is >> im)
        // Se leyó con éxito la parte real, la coma, y la parte imaginaria
        c.asignar(re, im);
    else
        // Error al leer la parte imaginaria
        is.setstate(std::ios::failbit);
    return is;
}

inline complex operator+( const complex& c, double r2) {
        return complex(real(c) + r2, imag(c));
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
    std::cout << "cc + c4 is " << cc + c4 << std::endl;
    std::cout << "cc + 4.2 is " << cc + 4.2 << std::endl;
    std::cout << "4.2 + c4 is " << 4.2 + c4 << std::endl;
    // 4.2.operator+(c4)
    complex cx;
    std::cin >> cx;
    std::cout << cx;
}
