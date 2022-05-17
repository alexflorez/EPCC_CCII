class Base {
public:
    Base(int v)
    : value_{v}
    {}
    int value() { return value_; }
private:
    int value_;
};

class Derived : Base {
public:
    Derived()
    : Base{42}
    {}
};

int main() {
    Base b{42};
    int x{b.value()};
    Derived d{};
    int y{d.value()};
}
