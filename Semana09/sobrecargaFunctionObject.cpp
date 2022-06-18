#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

struct Suma {
    int suma{0};
    void operator()(int n) {
        suma += n;
    }
};

int main() {
    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 10);
    Suma s = std::for_each(v.begin(), v.end(), Suma());
    std::cout << "The sum is " << s.suma << '\n';
}
