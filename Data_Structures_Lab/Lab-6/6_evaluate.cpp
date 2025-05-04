//Program to implement infix to postfix and postfix evaluation

#include <iostream>
#include <cctype>  // For isdigit()
#include <cstdlib> // For atof()
#include "StackList.h"  // Include the stack header file

using namespace std;

// Function prototypes
int precedence(char op);
bool isOperator(char ch);
void infixToPostfix(string infix, string &postfix);
double evaluatePostfix(string postfix);

// Global storage for infix expression
string infixExpression;

int main() {
    int choice;
    string postfixExpression;

    do {
        cout << "\nMenu\n";
        cout << "1. Get Infix\n";
        cout << "2. Convert Infix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character after entering choice

        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression: ";
                getline(cin, infixExpression);
                break;

            case 2:
                if (infixExpression.empty()) {
                    cout << "No infix expression stored. Please enter an infix expression first.\n";
                } else {
                    infixToPostfix(infixExpression, postfixExpression);
                    cout << "Postfix Expression: " << postfixExpression << endl;
                }
                break;

            case 3:
                if (postfixExpression.empty()) {
                    cout << "No postfix expression generated. Convert infix to postfix first.\n";
                } else {
                    double result = evaluatePostfix(postfixExpression);
                    cout << "Evaluated Result: " << result << endl;
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '=')
        return 1;  // Lowest precedence (right-to-left associativity)
    if (op == '+' || op == '-')
        return 2;
    if (op == '*' || op == '/' || op == '%')
        return 3;
    return 0; // For non-operators
}

// Function to check if character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

// Function to convert infix to postfix
void infixToPostfix(string infix, string &postfix) {
    StackList stack;
    postfix = "";

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch; // Append operands directly to output
        } else if (isOperator(ch)) {
            while (stack.peek() != -1 && precedence((char)stack.peek()) >= precedence(ch)) {
                postfix += (char)stack.pop();
            }
            stack.push(ch);
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (stack.peek() != -1 && (char)stack.peek() != '(') {
                postfix += (char)stack.pop();
            }
            stack.pop(); // Pop '('
        }
    }

    while (stack.peek() != -1) {
        postfix += (char)stack.pop();
    }
}

// Function to evaluate postfix expression
double evaluatePostfix(string postfix) {
    StackList stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert char to int
        } else {
            int val2 = stack.pop();
            int val1 = stack.pop();
            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                case '%': stack.push(val1 % val2); break;
                case '=': stack.push(val2); break; // Assignment operator
            }
        }
    }
    return stack.pop(); // Final result
}
