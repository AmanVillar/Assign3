#include "ExpressionManager.h"
#include <stack>

bool ExpressionManager::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int ExpressionManager::getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

bool ExpressionManager::isBalancedParentheses(const std::string& expression) {
    std::stack<char> stack;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty() || (c == ')' && stack.top() != '(') ||
                (c == '}' && stack.top() != '{') || (c == ']' && stack.top() != '[')) {
                return false; // unbalanced parentheses
            }
            stack.pop();
        }
    }

    return stack.empty();
}

std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operatorStack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // operand, add to postfix
        }
        else if (c == '(' || c == '{' || c == '[') {
            operatorStack.push(c); // opening parenthesis, push to stack
        }
        else if (c == ')' || c == '}' || c == ']') {
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                operatorStack.top() != '{' && operatorStack.top() != '[') {
                postfix += operatorStack.top(); // pop operators until matching opening parenthesis
                operatorStack.pop();
            }
            if (operatorStack.empty() || (c == ')' && operatorStack.top() != '(') ||
                (c == '}' && operatorStack.top() != '{') || (c == ']' && operatorStack.top() != '[')) {
                return "Invalid Expression"; // unbalanced parentheses
            }
            operatorStack.pop(); // pop the matching opening parenthesis
        }
        else if (isOperator(c)) {
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top(); // pop higher or equal precedence operators
                operatorStack.pop();
            }
            operatorStack.push(c); // push current operator to stack
        }
    }

    // pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        if (operatorStack.top() == '(' || operatorStack.top() == '{' || operatorStack.top() == '[') {
            return "Invalid Expression"; // unbalanced parentheses
        }
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}
