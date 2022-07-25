// Principio Abierto-Cerrado

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;

enum class Color { Rojo, Verde, Azul };
enum class Tamanho { Pequenho, Medio, Grande };

struct Producto {
    string nombre;
    Color color;
    Tamanho tamanho;
};

struct FiltroProductos {
    // typedef vector<Producto*> Elementos;
    using Elementos = vector<Producto*>;

    Elementos por_color(Elementos elementos, Color color);
    Elementos por_tamanho(Elementos elementos, Tamanho tamanho);
    Elementos por_color_y_tamanho(Elementos elementos, Tamanho tamanho, Color color);
};

FiltroProductos::Elementos FiltroProductos::por_color(Elementos elementos, Color color) {
    Elementos resultado;
    for (auto& e : elementos)
        if (e->color == color)
            resultado.push_back(e);
    return resultado;
}

FiltroProductos::Elementos FiltroProductos::por_tamanho(Elementos elementos, Tamanho tamanho) {
    Elementos resultado;
    for (auto& e : elementos)
        if (e->tamanho == tamanho)
            resultado.push_back(e);
   return resultado;
}

FiltroProductos::Elementos FiltroProductos::por_color_y_tamanho(
                            Elementos elementos, Tamanho tamanho, Color color) {
    Elementos resultado;
    for (auto& e : elementos)
        if (e->tamanho == tamanho and e->color == color)
            resultado.push_back(e);
    return resultado;
}

template <typename T>
struct Especificacion {
    virtual bool se_cumple(T* elemento) = 0;
};

template <typename T>
struct Filtro {
    virtual vector<T*> filtro(vector<T*> elementos, Especificacion<T>& espec) const = 0;
};

struct MejorFiltro : Filtro<Producto> {
    vector<Producto*> filtro(
                vector<Producto*> elementos,
                Especificacion<Producto>& espec) const override {
        vector<Producto*> resultado;
        for (auto& p : elementos)
            if (espec.se_cumple(p))
                resultado.push_back(p);
        return resultado;
    }
};

struct EspecificacionColor : Especificacion<Producto> {
    Color color;
    explicit EspecificacionColor(const Color color)
    : color{color}
    { }
    bool se_cumple(Producto* elemento) override {
        return elemento->color == color;
    }
};

struct EspecificacionTamanho : Especificacion<Producto> {
    Tamanho tamanho;
    explicit EspecificacionTamanho(const Tamanho tamanho)
    : tamanho{tamanho}
    { }
    bool se_cumple(Producto* elemento) override {
        return elemento->tamanho == tamanho;
    }
};

template <typename T>
struct EspecificacionAnd : Especificacion<T> {
    Especificacion<T>& primero;
    Especificacion<T>& segundo;

    EspecificacionAnd(Especificacion<T>& primero,
                      Especificacion<T>& segundo)
    : primero{primero}, segundo{segundo} {}
    bool se_cumple(T* elemento) override {
        return primero.se_cumple(elemento) && segundo.se_cumple(elemento);
    }
};

int main() {
    Producto manzana{ "Manzana", Color::Verde, Tamanho::Pequenho };
    Producto arbol{ "Arbol", Color::Verde, Tamanho::Grande };
    Producto casa{ "Casa", Color::Azul, Tamanho::Grande };
    vector<Producto*> productos{ &manzana, &arbol, &casa };
    MejorFiltro mf;
    EspecificacionColor verde(Color::Verde);
    auto productos_verdes = mf.filtro(productos, verde);
    for (auto& x : productos_verdes)
        cout << x->nombre << " es verde\n";

    EspecificacionTamanho grande(Tamanho::Grande);
    EspecificacionAnd<Producto> verde_y_grande{ grande, verde };

    auto productos_verdes_grandes = mf.filtro(productos, verde_y_grande);
    for (auto& x : productos_verdes_grandes)
        cout << x->nombre << " es verde y grande\n";
    // Arbol es verde y grande
}
