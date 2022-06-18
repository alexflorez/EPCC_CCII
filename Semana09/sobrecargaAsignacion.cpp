#include <algorithm>
#include <cassert>
#include <iostream>

class data {
public:
    data(int sz)
    : size{sz}, mArray{new int[sz]} { }

    ~data() {
        delete [] mArray;
    }

    // asignación copia
    data& operator=(const data& other) {
        // Evita la autoasignación
        if (this == &other)
            return *this;

        // assume *this manages a reusable resource, such as a heap-allocated buffer mArray
        if (size != other.size) {         // el recurso en *this no puede ser reusado
            delete[] mArray;              // liberar el recurso en *this
            mArray = nullptr;
            size = 0;
            mArray = new int[other.size]; // asignar recursos en *this
            size = other.size;
        }

        std::copy(other.mArray, other.mArray + other.size, mArray);
        return *this;
    }

    int& operator []( int i) {
        assert(i >= 0 && i < size );
        return mArray[i];
    }

    int length() const {
        return size;
    }
private:
    int *mArray;
    int size;
};

int main() {
    data d(5);
    for (int i = 0; i < d.length(); ++i)
        d[i] = i + 1;
    data p(3);
    p = d;
    for (int i = 0; i < p.length(); ++i)
        std::cout << p[i] << std::endl;
}
