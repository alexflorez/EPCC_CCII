#include <iostream>

class Base {
public:
    Base() { std::cout << "Base\n"; }
};

class Middle : public Base {
public:
    Middle() { std::cout << "Middle\n"; }
};

class Derived : public Middle {
public:
    Derived() { std::cout << "Derived\n"; }
};

int main() {
    Derived d;
}
