#include <iostream>

void countdown(int n) {
    if (n == 0) {
        std::cout << "Blastoff!";
    } else {
        std::cout << n << '\n';
        countdown(n - 1);
    }
}

int main() {
    int n{};
    std::cin >> n;
    countdown(n);
    return 0;
}
