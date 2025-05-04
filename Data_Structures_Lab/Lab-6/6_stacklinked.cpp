// Program to implement Stack ADT using a singly linked list.
#include <iostream>
using namespace std;

class StackList {
private:
    struct Node {
        char data;
        Node* next;
    } *top;

public:
    StackList() { top = nullptr; }  // Constructor
    ~StackList() {  // Destructor
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

// Main function (menu-driven)
int main() {
    StackList stack;
    int choice;
    char ch;

    do {
        cout << "Menu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice:\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the character to push:\n";
                cin >> ch;
                cout << stack.push(ch) << "\n";
                break;

            case 2:
                cout << "Popped: " << (char)stack.pop() << "\n";
                break;

            case 3:
                cout << "Top element: " << (char)stack.peek() << "\n";
                break;

            case 4:
                stack.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 5);
}

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
