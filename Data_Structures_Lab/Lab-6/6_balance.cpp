//Program to implement infix to postfix and postfix evaluation

#include <iostream>
#include "StackList.h"  // Using SLL-based Stack ADT

using namespace std;

// Function prototype
bool isBalanced(string expression);

int main() {
    int choice;
    string expression;

    do {
        cout << "\nMenu\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                getline(cin, expression);

                if (isBalanced(expression)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are NOT balanced.\n";
                }
                break;

            case 2:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}

// Function to check if the given parentheses string is balanced
bool isBalanced(string expression) {
    StackList stack;  // Using StackList (SLL-based stack)

    for (char ch : expression) {
        if (ch == '(') {
            stack.push(ch);  // Push opening bracket
        } else if (ch == ')') {
            if (stack.peek() == -1) {
                return false;  // Extra closing parenthesis
            }
            stack.pop();  // Match found, pop it
        }
    }

    return (stack.peek() == -1); // If stack is empty, balanced
}