#include <iostream>

class Base {
public:
    Base(int value)
    : value_{value}
    { std::cout << "Base(" << value << ")\n"; }
    Base()
    : Base{0}
    { std::cout << "Base()\n"; }
    Base(Base const& copy)
    : value_{copy.value_}
    { std::cout << "copy Base(" << value_ << ")\n"; }

    ~Base() { std::cout << "~Base(" << value_ << ")\n"; }

    int value() { return value_; }

    Base& operator++() {
        ++value_;
        return *this;
    }
private:
    int value_;
};

class Derived : public Base
{
public:
    Derived(int value): Base{value} { std::cout << "Derived(" << value << ")\n"; }
    Derived() : Base{} { std::cout << "Derived()\n"; }
    Derived(Derived const& copy)
    : Base{copy}
    { std::cout << "copy Derived(" << value() << "\n"; }

    ~Derived() { std::cout << "~Derived(" << value() << ")\n"; }
};

Derived make_derived() {
    return Derived{42};
}

Base increment(Base b) {
    ++b;
    return b;
}

void increment_reference(Base& b) {
    ++b;
}

int main() {
    Derived d{make_derived()};
    Base b{increment(d)};
    increment_reference(d);
    increment_reference(b);
    Derived a(d.value() + b.value());
}
