#include <iostream>

std::string DecToBinary(int num) {
  std::string Binary;
  std::string temp;
  while (num) {
    temp += std::to_string(num % 2);
    num /= 2;
  }
  int length = temp.length();
  if (length < 7) {
      for (int i = 0; i < 7 - length; i++) {
          temp += '0';
      }
  }
  for (int i = 6; i >= 0 ; i--) {
    Binary += temp[i];
  }
  return Binary;
}

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
    // Stack myStack;
    // for (int i = 0; i < 10; i++) {
    //     myStack.push(i);
    // }
    // for (int i = 0; i < 10; i++) {
    //     std::cout << myStack.top() << " ";
    //     myStack.pop();
    // }
    int num = 15;
    std::cout << DecToBinary(num);
    return 0;
}
