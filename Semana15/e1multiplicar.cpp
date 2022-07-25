#include <iostream>
using namespace std;

void multiplicarAuto(auto& v, int valor) {
    for (auto& x : v)
        for (auto& y : x)
            for (auto& z : y)
                z = z * valor;
}

void imprimirMatriz(auto& v) {
    for (auto& x : v) {
        cout << "[\n";
        for (auto &y: x) {
            cout << "{ ";
            for (auto &z: y) {
                cout << z << " ";
            }
            cout << "}\n";
        }
        cout << "]\n";
    }
}

template<int N>
void duplicar(int (&m)[N][N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                m[i][j][k] *= 2;
            }
        }
    }
}

template<int N, int F, int C>
void multiplicarTemplate(int (&m)[N][F][C], int value) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < F; ++j) {
            for (int k = 0; k < C; ++k) {
                m[i][j][k] *= value;
            }
        }
    }
}


int main() {
    int x[3][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
                      {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
                      {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}};

    int y[3][4][2] = {{{1, 2}, {4, 5}, {7, 8}, {1, 2}},
                      {{10, 11}, {13, 14}, {16, 17}, {1, 2}},
                      {{19, 20}, {22, 23}, {25, 26}, {1, 2}}};
    multiplicarAuto(x, 3);
    multiplicarTemplate(y, 4);

    imprimirMatriz(x);
    cout << '\n';
    imprimirMatriz(y);
}
