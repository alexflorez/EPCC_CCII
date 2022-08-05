#include <vector>
#include <set>
#include <iostream>
#include <cassert>
#include <numeric>

using std::vector;
using std::cout;

template<typename T>
T absoluto(T x) {
    if (x < 0)
        return -x;
    else
        return x;
}

template<typename Container, typename Iterator>
Iterator copy(Container container, Iterator start) {
    for (auto const& item : container) {
        *start = item;
        ++start;
    }
    return start;
}

template<typename Iterator, typename T>
Iterator find(Iterator start, Iterator end, T value) {
    while(start != end) {
        if (*start == value)
            return start;
        ++start;
    }
    return end;
}

template<typename T>
T min(T a, T b) {
    if (b < a)
        return b;
    else
        return a;
}

template<typename T, typename U>
U sumar_datos(std::istream& in) {
    T x{};
    U total{0};
    while (in >> x)
        total += x;
    return total;
}


class Racional {
public:
    Racional(): Racional{0} {}
    Racional(int num): numerator_{num}, denominator_{1} {} // no need to reduce
    Racional(Racional const&) = default;
    Racional(int num, int den)
    : numerator_{num}, denominator_{den} {
        reduce();
    }
    Racional(double r)
    : Racional{static_cast<int>(r * 100000), 100000} {
        reduce();
    }
    int numerator() const { return numerator_; }
    int denominator() const { return denominator_; }

    float to_float() const {
        return static_cast<float>(numerator()) / denominator();
    }
    double to_double() const {
        return static_cast<double>(numerator()) / denominator();
    }
    long double to_long_double() const {
        return static_cast<long double>(numerator()) / denominator();
    }
    template<typename T>
    T convert() {
        return static_cast<T>(this->numerator()) / this->denominator();
    }
/// Assign a numerator and a denominator, then reduce to normal form.
    void assign(int num, int den) {
        numerator_ = num;
        denominator_ = den;
        reduce();
    }
private:
/// Reduce the numerator and denominator by their GCD.
    void reduce() {
        assert(denominator() != 0);
        if (denominator() < 0) {
            denominator_ = -denominator();
            numerator_ = -numerator();
        }
        int div{std::gcd(numerator(), denominator())};
        numerator_ = numerator() / div;
        denominator_ = denominator() / div;
    }
    int numerator_;
    int denominator_;
};

int main() {
    // int x{ -42 };
    // int y{ absoluto(x) };

    vector<int> a{1, 2, 3, 4, 5};
    // vector<int> b(a.size(), 0);
    vector<int> b{};// (a.size(), 0);
    ::copy(a, b.begin());
    std::set<int> s{4, 6, 8, 10, 12};
    ::copy(s, b.begin());
    for (auto e: b)
        cout << e << '\n';
    ::find(std::begin(s), std::end(s), 4);

    int x{ 10 };
    int y{ 20 };
    int z{ ::min(x, y) };

    int u{ 10 };
    long v{ 20 };
    std::cout << ::min<long>(u, v);

    long suma{ sumar_datos<int, long>(std::cin) };
    std::cout << suma << '\n';

    Racional r{42, 10};
    double d{ r.convert<double>() };
    cout << d << std::endl;
}
