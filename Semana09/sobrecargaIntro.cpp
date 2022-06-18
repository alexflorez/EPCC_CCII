#include <cassert>
#include <iostream>

class vector {
public:
    explicit vector(int size)
    // vector(int size)
    : my_size{size}, data{new double[size]} { }
    ~vector() {
        delete [] data;
    }
    // RAII
    double at(int i) {
        assert(i >= 0 && i < my_size );
        return data[i];
    }

    double& operator []( int i) {
        assert(i >= 0 && i < my_size );
        return data[i];
    }

    int size() const {
        return my_size;
    }
private:
    double *data;
    int my_size;
};

int main() {
    vector v(5);
    // vector v = 5;
    for (int i = 0; i < v.size(); ++i)
        v[i] = i + 1;
    // double sum = 0.0;
    // for (int i = 0; i < v.size (); ++i)
    //     sum += v.at(i);

    double sum = 0.0;
    for (int i = 0; i < v.size(); ++i)
        sum += v[i];
    // int i = 0;
    // v[i];
    // v.operator[](i);
    std::cout << sum << std::endl;
}
