#include <iostream>
#include <cmath>

std::pair<bool, std::pair<double, double>> quadratic(double a, double b, double c){
	// calcular el radical y comprobar si es negativo
	double radical = std::pow(b, 2) - (4 * a * c);

	if (radical > 0) {
		double raiz1 = ( -1 * b + std::sqrt(radical) ) / (2 * a);
		double raiz2 = ( -1 * b - std::sqrt(radical) ) / (2 * a);
		// Podemos usar:
        // return std::make_pair(true, std::make_pair(raiz1, raiz2));
		// O usando inicializacion uniforme
		return {true, {raiz1, raiz2}};
	} else {
        // Podemos usar:
        // return std::make_pair(false, std::make_pair(-1, -1));
		// O usando inicializacion uniforme
		return {false, {-1, -1}};
	}
}

int main() {
	// Leemos 3 numeros (ax^2 + bx + c)
	double a{};
    double b{};
    double c{};
	std::cout << "Coeficientes de entrada" << std::endl;
	std::cin >> a >> b >> c;

	// Calcularmos las raices si existen
	// Podemos usar:
    // std::pair<bool, std::pair<double, double>> resultado = quadratic(a, b, c);
	// Usando auto para deduccion de tipos
	auto resultado = quadratic(a, b, c);
	bool existe = resultado.first;
	auto raices = resultado.second;

	// if (resultado.first) {
	if (existe) {
		double raiz1 = raices.first;
		double raiz2 = raices.second;
		// std::cout << "Las soluciones son: " << resultado.second.first << " " << resultado.second.second << std::endl;
		std::cout << "Las soluciones son: " << raiz1 << " " << raiz2 << std::endl;
	} else {
		std::cout << "No existen soluciones reales" << std::endl;
	}

	return 0;
}
