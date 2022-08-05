#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <string_view>

class Persona {
public:
    Persona() : nombre_{}, direccion_{}, telefono_{} {}
    Persona(std::string_view nombre,
            std::string_view direccion,
            std::string_view telefono)
            : nombre_{nombre}, direccion_{direccion}, telefono_{telefono}
    { }
    std::string const& nombre() const { return nombre_; }
    std::string const& direccion() const { return direccion_; }
    std::string const& telefono() const { return telefono_; }
private:
    std::string nombre_, direccion_, telefono_;
};

/*template<typename T>
struct less {
    bool operator()(T const& a, T const& b) const {
        return a < b;
    }
};*/

namespace std {
    template<>
    struct less<Persona> {
        bool operator()(Persona const& a, Persona const& b) const {
            return a.nombre() < b.nombre();
        }
    };
}

//bool operator<(Persona const& a, Persona const& b) {
//    return a.nombre() < b.nombre();
//}

int main() {
    std::map<Persona, int> gente;
    Persona joe {"Joe", "Av 100", "765-4321"};
    Persona jane {"Jane", "Pasaje 234", "123-4567"};
    gente[joe] = 42;
    gente[jane]= 10;
    for (auto [persona, numero] : gente)
        std::cout << persona.nombre() << ' ' << numero << '\n';
}
