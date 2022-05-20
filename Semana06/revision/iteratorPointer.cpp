#include <iostream>
#include <deque>
#include <vector>

using std::cout;
using std::endl;

int main() {
    // Inicializacion de punteros y desreferencias
    int x{5};
    int* pointerToX = &x; // inicializado en la direccion de x
    cout << "Valor puntero void pointerToX: " << (void*)pointerToX << endl;
    cout << "Valor de x: " << x << endl;
    cout << "Valor del entero apuntado por pointerToX: " << *pointerToX << endl << endl;

    std::vector<int> vec{1, 2, 3, 6, 11, 23};
    cout << "Valores en el vector: ";
    for (auto item : vec)
        cout << item << " ";
    cout << endl;

    // Las direcciones son numeros.
    // Por lo tanto, para contenedores que tienen elementos en direcciones consecutivas
    // el operador "++" sera equivalente para punteros e iteradores
    int* pointerToVec = &vec[0];
    std::vector<int>::iterator vectorIterator = vec.begin();
    cout << "\tValor del puntero void pointerToVec: \t" << (void *)pointerToVec << endl;
    cout << "\tValor del entero *pointerToVec: \t" << *pointerToVec << endl;
    cout << "\tValor del entero *vectorIterator: \t" << *vectorIterator << endl << endl;

    // Incrementando el puntero y el iterador al siguiente elemento con ++
    pointerToVec++;       // agrega 1 a la direccion de vec[0] para obtener la direccion de vec[1]
    vectorIterator++;
    cout << "Despues de incrementar:" << endl;
    cout << "\tValor del puntero void pointerToVec: \t" << (void *)pointerToVec << endl;
    cout << "\tValor del entero *pointerToVec: \t" << *pointerToVec << endl;
    cout << "\tValor del entero *vectorIterator: \t" << *vectorIterator << endl << endl;

    // Usando una cola doblemente enlazada
    std::deque<int> deq{};
    for (int i{0}; i < 10; ++i) {
         if (i % 2 == 0)
            deq.push_back(i);
         else
            deq.push_front(i);
    }
    // Puntero a un elemento de un deque
    int* pointerToDeq = &deq[0];
    std::deque<int>::iterator dequeIterator = deq.begin();
    cout << "Valor del puntero void pointerToDeq: \t" << (void *)pointerToDeq << endl;
    cout << "\tValor del entero *pointerToDeq: \t" << *pointerToDeq << endl;
    cout << "\tValor del entero *dequeIterator: \t" << *dequeIterator << endl << endl;

    // Incrementando el puntero y el iterador al siguiente elemento con ++
    cout << "Despues de incrementar:" << endl;
    for (int i{1}; i < 10; ++i) {
        pointerToDeq++;       // agrega 1 a la direccion de deq[i] para obtener la direccion de deq[i+1]
        dequeIterator++;
        cout << "Valor del puntero void pointerToDeq: \t" << (void *)pointerToDeq << endl;
        cout << "\tValor del entero *pointerToDeq: \t" << *pointerToDeq << endl;
        cout << "\tValor del entero *dequeIterator: \t" << *dequeIterator << endl;
    }

    return 0;
}

