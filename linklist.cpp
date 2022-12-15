#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node *head = nullptr;
private:
    Node *tail = nullptr;
    int count = 0;
public:
    void add(int data) {
        Node *newNode = new Node(data);
        if (this->count == 0) {
            this->head = newNode;
            this->tail = newNode;
            this->count++;
        } else {
            this->tail->next = newNode;
            this->tail = this->tail->next;
            this->count++;
        }
    }
    void display() {
        Node *tmp = this->head;
        while (tmp != nullptr) {
            std::cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        std::cout << "NULL";
    }
};

int main() {
    LinkedList *list = new LinkedList();
    for (int i = 0; i < 10; i++) {
        list->add(i);
    }
    list->display();
    return 0;
}