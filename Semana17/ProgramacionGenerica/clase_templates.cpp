#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <numeric>

template<typename T>
class Racional {
public:
    using value_type = T;
    Racional() : Racional{0} {}
    Racional(value_type num) : numerator_{num}, denominator_{1} {}
    Racional(value_type num, value_type den);
    void assign(value_type num, value_type den);
    Racional const& operator +=(Racional const& rhs);
    Racional const& operator -=(Racional const& rhs);
    Racional const& operator *=(Racional const& rhs);
    Racional const& operator /=(Racional const& rhs);
    template<typename U>
    U convert() const {
        return static_cast<U>(numerator()) / static_cast<U>(denominator());
    }
    value_type const& numerator() const { return numerator_; }
    value_type const& denominator() const { return denominator_; }

    template<typename U>
    Racional& operator=(Racional<U> const& rhs);
private:
    void reduce();
    value_type numerator_;
    value_type denominator_;
};

template<typename T>
Racional<T> operator-(Racional<T> const& r) {
    return Racional{-r.numerator(), r.denominator()};
}

template<typename T>
void Racional<T>::reduce() {
    if (denominator() == value_type{})
        throw std::logic_error("divide by zero in rational");
    if (denominator() < value_type{}) {
        denominator_ = -denominator();
        numerator_ = -numerator();
    }
    int div{std::gcd(numerator(), denominator())};
    numerator_ = numerator() / div;
    denominator_ = denominator() / div;
}


template<typename T>
Racional<T>::Racional(value_type num, value_type den)
: numerator_{num}, denominator_{den} {
    reduce();
}

template<typename T>
void Racional<T>::assign(value_type num, value_type den) {
    numerator_ = num;
    denominator_ = den;
    reduce();
}

template<typename T>
bool operator==(Racional<T> const& a, Racional<T> const& b) {
    return a.numerator() == b.numerator() and
           a.denominator() == b.denominator();
}

template<typename T>
inline bool operator!=(Racional<T> const& a, Racional<T> const& b) {
    return not (a == b);
}

template<typename T>
Racional<T> const& Racional<T>::operator/=(Racional const& rhs) {
    numerator_ *= rhs.denominator();
    denominator_ *= rhs.numerator();
    if (denominator_ < value_type{}) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    reduce();
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, Racional<T> const& r) {
    std::cout << r.numerator() << '/' << r.denominator();
    return stream;
}


template<typename T>
template<typename U>
Racional<T>& Racional<T>::operator=(Racional<U> const& rhs) {
    assign(rhs.numerator(), rhs.denominator());
    return *this;
}

template<typename T>
T absoluto(T x) {
    if (x < 0)
        return -x;
    else
        return x;
}

template<typename T>
Racional<T> absoluto(Racional<T> const& r) {
    if (r.numerator() < 0)
        return -r;
    else
        return r;
}


//template<typename T> constexpr T pi_v = 3.141592653589793238462643383279502884L;
//constexpr double pi = pi_v<double>;

template<typename T>
inline const Racional<T> pi{ 31416, 10000 };

int main() {
    Racional<short> zero{};
    Racional<int> pi1{355, 113};
    Racional<long> pi2{80143857L, 25510582L};
    //std::map<long, int> mapa;
    std::vector<std::vector<int>> matrix;

    Racional<int> little{};
    Racional<long> big{};
    big = little;

    std::cout << pi<int>;

    Racional neg{-14, 23};
    std::cout << absoluto(-5) << '\n';
    std::cout << absoluto(neg) << '\n';

}
