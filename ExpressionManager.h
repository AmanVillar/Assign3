#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <string>

class ExpressionManager {
public:
    //function to check if a character is an operator
    static bool isOperator(char c);

    //function to determine the precedence of an operator
    static int getPrecedence(char op);

    //function to check for balanced parentheses in an expression
    static bool isBalancedParentheses(const std::string& expression);

    //function to convert infix expression to postfix expression
    static std::string infixToPostfix(const std::string& infix);
};

#endif 
