#include <iostream>
#include "ExpressionManager.h"

using namespace std;

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    if (ExpressionManager::isBalancedParentheses(infixExpression)) {
        string postfixExpression = ExpressionManager::infixToPostfix(infixExpression);
        if (postfixExpression == "Invalid Expression") {
            cout << "Invalid Expression" << endl;
        }
        else {
            cout << "Postfix Expression: " << postfixExpression << endl;
        }
    }
    else {
        cout << "Expression has unbalanced parentheses." << endl;
    }

    return 0;
}

 








