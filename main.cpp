# Assign3
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

bool isBalancedParentheses(const string& expression) {
    stack<char> stack;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty() || (c == ')' && stack.top() != '(') ||
                (c == '}' && stack.top() != '{') || (c == ']' && stack.top() != '[')) {
                return false; // Unbalanced parentheses
            }
            stack.pop();
        }
    }

    return stack.empty();
}

string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> operatorStack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(' || c == '{' || c == '[') {
            operatorStack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   operatorStack.top() != '{' && operatorStack.top() != '[') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (operatorStack.empty() || (c == ')' && operatorStack.top() != '(') ||
                (c == '}' && operatorStack.top() != '{') || (c == ']' && operatorStack.top() != '[')) {
                return "Invalid Expression"; // Unbalanced parentheses
            }
            operatorStack.pop();
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                   getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        if (operatorStack.top() == '(' || operatorStack.top() == '{' || operatorStack.top() == '[') {
            return "Invalid Expression"; // Unbalanced parentheses
        }
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    if (isBalancedParentheses(infixExpression)) {
        string postfixExpression = infixToPostfix(infixExpression);
        if (postfixExpression == "Invalid Expression") {
            cout << "Invalid Expression" << endl;
        } else {
            cout << "Postfix Expression: " << postfixExpression << endl;
        }
    } else {
        cout << "Expression has unbalanced parentheses." << endl;
    }

    return 0;
}
 








