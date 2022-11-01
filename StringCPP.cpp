#include <iostream>

int main() {
    // std::string myName = "Truong Manh Khoi";
    // std::cout << myName << std::endl;
    // myName[11] = '\0';
    // std::cout << myName << std::endl;
    // return 0;
    char myName[] = "Truong Manh Khoi";
    std::cout << myName << std::endl;
    myName[11] = 0;
    std::cout << myName << std::endl;
    return 0;
    int a = 10, b = 20;
    std::cout << a + b;
}
