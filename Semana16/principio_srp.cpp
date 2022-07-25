// Principio de Responsabilidad Unica
// SRP

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::endl;
using std::ofstream;

struct Diario {
    string titulo;
    vector<string> entradas;

    explicit Diario(string  titulo)
    : titulo{std::move(titulo)}
    { }

    void agregar(const string &entrada);
    // guardar no deberia estar dentro de Diario
    void guardar(const string &nombre_archivo);
};

void Diario::agregar(const string& entrada) {
    static int contador{1};
    entradas.push_back(std::to_string(contador) + ": " + entrada);
    ++contador;
}

void Diario::guardar(const string& nombre_archivo) {
    ofstream ofs(nombre_archivo);
    for (auto& s : entradas)
        ofs << s << endl;
}

struct AdministradorPersistencia {
    static void guardar(const Diario& d, const string& nombre_archivo) {
        ofstream ofs(nombre_archivo);
        for (auto& s : d.entradas)
            ofs << s << endl;
    }
};

int main() {
    Diario d{"Mes Julio"};
    d.agregar("Sali a caminar");
    d.agregar("Jugue futbol");

    // d.guardar("diario.txt");
    AdministradorPersistencia::guardar(d, "diario.txt");
}
