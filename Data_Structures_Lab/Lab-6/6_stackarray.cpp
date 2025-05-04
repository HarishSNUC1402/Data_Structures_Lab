#include <iostream>
using namespace std;

#define SIZE 5  // Stack size

class StackArray {
private:
    char stack[SIZE];  // Character stack
    int top;           // Top pointer

public:
    StackArray() { top = -1; }  // Constructor
    ~StackArray(){}
    
    };  // Destructor
    int push(char ch);
    int pop();
    int peek();
    void display();
};

// Main function (menu-driven)
int main() {
    StackArray stack;
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
int StackArray::push(char ch) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
        return -1;
    }
    stack[++top] = ch;
    return 1;
}

// Pop operation
int StackArray::pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack[top--];
}

// Peek operation
int StackArray::peek() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return stack[top];
}

// Display stack
void StackArray::display() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << "\n";
}
