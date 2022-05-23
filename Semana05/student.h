#ifndef PROGRAMMING_STUDENT_H
#define PROGRAMMING_STUDENT_H

#include <string>

class Student {
public:
    Student();
    Student(std::string name, std::string city, int age);

    std::string getName();
    void setName(std::string name);
    std::string getCity();
    void setCity(std::string city);
    int getAge();
    void setAge(int age);

private:
    std::string name;
    std::string city;
    int age{};
};


#endif //PROGRAMMING_STUDENT_H
