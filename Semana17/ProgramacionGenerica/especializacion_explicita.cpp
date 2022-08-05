#include <type_traits>
#include <iostream>


template<class T>
class is_void : public std::false_type
{ };

template<>
class is_void<void> : public std::true_type
{ };

void print(int a) {
    std::cout << a << std::endl;
}

int main() {
    int n{5};
    std::cout << std::boolalpha;
    std::cout << is_void<int>::value << std::endl;
    std::cout << is_void<decltype(print(n))>::value << std::endl;
}
