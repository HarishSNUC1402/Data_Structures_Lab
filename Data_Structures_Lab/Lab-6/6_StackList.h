//Header file of Stack ADT implementation using Linked List.
#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>
using namespace std;

class StackList {
private:
    struct Node {
        char data;
        Node* next;
    } *top;

public:
    StackList() { top = nullptr; } // Constructor inside class
    ~StackList() {  // Destructor inside class
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    int push(char ch);
    int pop();
    int peek();
    void display();
};

// Push operation
int StackList::push(char ch) {
    Node* newnode = new Node;
    if (!newnode) {
        cout << "Stack Overflow\n";
        return -1;
    }
    newnode->data = ch;
    newnode->next = top;
    top = newnode;
    return 1;
}

// Pop operation
int StackList::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow\n";
        return -1;
    }
    Node* temp = top;
    char ch = temp->data;
    top = top->next;
    delete temp;
    return ch;
}

// Peek operation
int StackList::peek() {
    if (top == nullptr) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return top->data;
}

// Display stack
void StackList::display() {
    if (top == nullptr) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Stack: ";
    Node* temp = top;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

#endif // STACKLIST_H