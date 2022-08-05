#include <string>
#include <utility>
#include <iostream>

using std::string;
using std::cout;

std::pair<int, int> make_point(int x, int y) {
    return std::make_pair(x, y);
}

const string message { "Test" };
const string& echo() {
    return message;
}

int main() {
    auto a { 123 }; // x es de tipo int
    auto result {make_point(4, 5)};

    auto f1 { echo() };
    cout << f1 << '\n';
    const auto& f2 { echo() };

    int i { 123 };
    // auto p { &i };
    auto* p { &i };

    const auto p1 { &i };
    auto const p2 { &i };
    const auto* p3 { &i };

    int x { 123 };
    decltype(x) y { 456 };

    decltype(echo()) f3 { echo() };
}
