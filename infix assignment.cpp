#include <iostream>
#include "Polish.h"
#include <stack>
#include <string>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperand(char c) {
    return c >= '1' && c <= '9';
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // Assuming '(' has the lowest precedence
}

std::string readInfix()
{
    std::string infix;
    std::cout << "Please enter the infix expression";
    std::cin >> infix;
        //return std::string();
        return infix;
}

std::string convertToPostfix(std::string infix) {
    std::string postfix;
    std::stack<char> S;

    for (char& token : infix) {
        if (isOperand(token)) {
            postfix.push_back(token);
        }
        else if (token == '(' || token == '[' || token == '{') {
            S.push(token);
        }
        else if (token == ')' || token == ']' || token == '}') {
            while (!S.empty() && S.top() != '(' && S.top() != '[' && S.top() != '{') {
                postfix.push_back(S.top());
                S.pop();
            }
            S.pop(); // Discard the opening parenthesis
        }
        else if (isOperator(token)) {
            while (!S.empty() && precedence(S.top()) >= precedence(token)) {
                postfix.push_back(S.top());
                S.pop();
            }
            S.push(token);
        }
    }

    while (!S.empty()) {
        postfix.push_back(S.top());
        S.pop();
    }

    return postfix;
}

int evaluate(std::string postfix) {
    std::stack<int> operands;

    for (char& token : postfix) {
        if (isOperand(token)) {
            operands.push(token - '0'); // Convert char to int
        }
        else if (isOperator(token)) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result;

            switch (token) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 != 0) {
                    result = operand1 / operand2;
                }
                else {
                    std::cerr << "Error: Division by zero\n";
                    return 0; // or any other error handling
                }
                break;
            default:
                std::cerr << "Error: Invalid operator\n";
                return 0; // or any other error handling
            }

            operands.push(result);
        }
    }

    if (!operands.empty()) {
        return operands.top();
    }
    else {
        std::cerr << "Error: Empty expression\n";
        return 0; // or any other error handling
    }
}
