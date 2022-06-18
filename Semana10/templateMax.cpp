#include <iostream>

//int max(int a, int b) {
//    if (a > b)
//        return a;
//    else
//        return b;
//}
//
//double max(double a, double b) {
//    if (a > b)
//        return a;
//    else
//        return b;
//}

//template <typename T>
//T max(T a, T b) {
//    if (a > b)
//        return a;
//    else
//        return b;
//}

//template <typename T>
//inline T max(T x, T y) {
//    return x > y ? x.value : y.value;
//}

//inline int max(int a, int b) {
//    return a > b ? a : b;
//}

// C++ 14
//template <typename T, typename U>
//auto max(T a, U b) {
//    return a > b ? a : b;
//}

// C++ 20
auto max(auto a, auto b) {
    return a > b ? a : b;
}

int main() {
    std::cout << "El maximo de 3 y 5 es " << max(3, 5) << '\n';
    std::cout << "El maximo de 3 y 5 es " << max(3l, 5l) << '\n';
    std::cout << "El maximo de 3 y 5 es " << max(3.0, 5.0) << '\n';

    unsigned u1= 2, u2= 8;
    std::cout << "El maximo de u1 y u2 es " << max(u1, u2) << '\n';
    std::cout << "El maximo de u1*u2 y u1+u2 es " << max(u1*u2, u1+u2) << '\n';

    std::cout << max<float>(8.1, 9.3) << '\n';

    unsigned u= 2;
    int i= 3;
    std::cout << "El maximo de u e i es " << max(int(u), i) << '\n';
    std::cout << "El maximo de u e i es " << max<int>(u, i) << '\n';
    std::cout << "El maximo de u e i es " << max(u, i) << '\n';

}
