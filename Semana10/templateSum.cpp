#include <iostream>

template <typename T>
T sum(const T* array, int n) {
    T sum{0};
    for (int i{0}; i < n; ++i)
        sum+= array[i];
    return sum;
}

template <typename T, unsigned N>
T sum(const T (&array)[N]) {
    T sum{0};
    for (int i{0}; i < N; ++i)
        sum+= array[i];
    return sum;
}

template <typename T>
inline T accumulate_array(T* a, T* a_end) {
    T sum{0};
    for (; a != a_end; ++a)
        sum+= *a;
    return sum;
}

template <typename Iter , typename T>
inline T accumulate(Iter it, Iter end, T init) {
    for (; it != end; ++it)
        init+= *it;
    return init;
}

int main() {
    int ai[]= {2, 4, 7, 8};
    double ad[]= {2.0, 4.5, 7.0};

    std::cout << "La suma de ai es " << sum(ai, 4) << '\n';
    std::cout << "La suma de ad es " << sum(ad, 3) << '\n';

    std::cout << "La suma de ai es " << sum(ai) << '\n';
    std::cout << "La suma de ad es " << sum(ad) << '\n';

    std::cout << "La suma de ai es " << accumulate_array(ai, &ai[3]) << '\n';
    std::cout << "La suma de ad es " << accumulate_array(ad, ad + 3) << '\n';
//
//    std::cout << "La suma de ad es " << accumulate(ad, ad + 3, 0.0) << '\n';
}