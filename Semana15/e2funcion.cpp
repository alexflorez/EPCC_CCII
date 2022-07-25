#include <iostream>
using namespace std;

double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

template<typename Func>
double funcion(Func f, double a, double b) {
    return f(a, b);
}

double operation(double (*op)(double, double), double a, double b){
    return (*op)(a,b);
}

float sumafi(float a, int b) {
    return a + b;
}

double restalf(float a, double b) {
    return a - b;
}

long multiplicaid(int a, long b) {
    return a * b;
}

template<typename Func, typename T, typename U=T>
auto funcion(Func f, T t, U u) {
    return f(t, u);
}

int main() {
    cout << funcion(suma, 3, 5) << endl;
    cout << funcion(resta, 3, 5) << endl;
    cout << funcion(multiplicar, 3, 5) << endl;
//    double (*op)(double, double);
//    op = suma;
//    cout << op(3, 5) << endl;
//    op = resta;
//    cout << op(3, 5) << endl;

//    cout << funcion(suma, 4, 5) << endl;
//    cout << funcion(resta, 4, 5) << endl;
//    cout << funcion(multiplicar, 4, 5) << endl;
//
    cout << funcion(sumafi, 4, 5) << endl;
    cout << funcion(restalf, 4, 5) << endl;
    cout << funcion(multiplicaid, 4, 5) << endl;

}