#include <iostream>

// Un objeto de este tipo representa una función lineal de una variable a * x + b.
struct Lineal {
    double a, b;

    double operator()(double x) const {
        return a * x + b;
    }
};

int main() {
    Lineal f{2, 1};  // Representa la función 2x + 1.
    Lineal g{-1, 0}; // Representa la función -x.
    // f y g son objetos que se pueden usar como una función.

    double f_0 = f(0);
    double f_1 = f(1);
    std::cout << f_0 << std::endl;
    std::cout << f_1 << std::endl;

    double g_0 = g(0);
    std::cout << g_0 << std::endl;
}