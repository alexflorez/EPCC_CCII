#include <iostream>

int leerNumero() {
    std::cout << "Ingrese un numero: ";
    int x{};
    std::cin >> x;
    return x;
}

void escribirRespuesta(int x) {
    std::cout << "La respuesta es " << x << '\n';
}

int main() {
    int x { leerNumero() };
    int y { leerNumero() };
    escribirRespuesta(x + y);
    return 0;
}
