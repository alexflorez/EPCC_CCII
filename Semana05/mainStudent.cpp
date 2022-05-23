#include "student.h"
#include <iostream>

int main(){
    try {
        Student silvia;
        silvia.setName("Silvia");
        silvia.setAge(-4);
        silvia.setCity("Arequipa");
        std::cout << silvia.getName() << " es de " << silvia.getCity()
                  << " tiene " << silvia.getAge() << " años" << std::endl;
    } catch (std::logic_error const& ex) {
        std::cout << ex.what() << '\n';
    }
    Student melgar{"Melgar", "Arequipa", 24};
    std::cout << melgar.getName() << " es de " << melgar.getCity()
              << " tiene " << melgar.getAge() << " años" << std::endl;
}
