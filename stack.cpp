#include <iostream>

class Stack {
    int *arr;
    int sizes;
    int cap = 1024;
public:
    Stack() {
        arr = new int(this->cap);
        this->sizes = 0;
    }
    void push(int data) {
        if (this->sizes < this->cap) {
            arr[this->sizes] = data;
        }
        this->sizes++;
    }
    void pop() {
        arr[this->sizes] = 0;
        this->sizes--;
    }
    int size() {
        return this->sizes;
    }
    bool empty() {
        return !this->sizes;
    }
    int top() {
        return this->arr[this->sizes - 1];
    }
};

int main() {
    Stack myStack;
    for (int i = 0; i < 10; i++) {
        myStack.push(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    return 0;
}