#include<iostream>

int main() {
    int a{10};
    void *ptr = &a;
    std::cout << *(int *)ptr << std::endl;
    std::cout << *(double *)ptr << std::endl;
    return 0;
}
