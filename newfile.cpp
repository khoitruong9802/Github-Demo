#include <iostream>

int add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    std::cout << "Hello world";
    int test1, test2;
    test1 = 100;
    test2 = 124;
    std::cout << add(test1, test2);
    return 0;
}