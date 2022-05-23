#include <stdexcept>
#include "student.h"

Student::Student()
: name{""}, city{""}, age{0}
{ }

Student::Student(std::string name, std::string city, int age)
: name{name}, city{city}, age{age}
{ }

std::string Student::getName() {
    return name;
}

void Student::setName(std::string name) {
    this->name = name;
}

std::string Student::getCity() {
    return city;
}

void Student::setCity(std::string city) {
    this->city = city;
}

int Student::getAge() {
    return age;
}

void Student::setAge(int age) {
    if (age >= 0)
        this->age = age;
    else
        throw std::logic_error("La edad no puede ser un numero negativo");
}
