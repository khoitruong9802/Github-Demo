#include <iostream>

int main() {
    int arr[100];
    int N, sum = 0;
    std::cout << "Nhap so phan tu = ";
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    std::cout << "SUM = " << sum;
}