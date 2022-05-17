#include <iostream>

#include "polimorfismo.h"

void showoff(Work& w) {
    w.print(std::cout);
    std::cout << '\n';
}

int main() {
    Book sc{"1", "El viejo y el mar", "Ernest Hemingway", 1951};
    Book ecpp{"2", "Atomic Habits", "James Clear", 2018};
    Periodical pop{"3", "Selecciones", 13, 42, "1 Enero 2000"};
    Periodical today{"4", "Times", 1, 1, "13 Febrero 2020"};

    showoff(sc);
    showoff(ecpp);
    showoff(pop);
    showoff(today);
}
