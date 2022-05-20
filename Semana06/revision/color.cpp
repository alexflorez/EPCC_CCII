#include <iomanip>
#include <iostream>

class Color {
public:
    Color()
    : Color{0, 0, 0}
    {}
    Color(Color const&) = default;
    Color(int r, int g, int b)
    : red_{r}, green_{g}, blue_{b}
    {}

    int red() const { return red_; }
    int green() const { return green_; }
    int blue() const { return blue_; }

    long int combined() const {
        return ((red() * 256L + green()) * 256) + blue();
    }

private:
    int red_;
    int green_;
    int blue_;
};

bool ordenColor(Color const& a, Color const& b) {
    return a.combined() < b.combined();
}

// Escribir un Color en formato: #RRGGBB.
std::ostream& operator<<(std::ostream& out, Color const& c) {
    // El manipulador hex le indica al flujo (stream) que lea o escriba en hexadecimal (base 16).
    out << '#' << std::hex << std::setw(6) << std::setfill('0') << c.combined();
    return out;
}

int main() {
    Color c1{10, 120, 150};
    Color c2{110, 12, 15};
    std::cout << c1 << '\n';
    std::cout << c2 << '\n';
    if (ordenColor(c1, c2))
        std::cout << "El mayor es " << c1 << std::endl;
    else
        std::cout << "El mayor es " << c2 << std::endl;
}
