#include <iostream>
#include <string>
#include <stack>

bool isBalanced(std::string input) {
    std::stack<char> paren;

    int i{ 0 };

    while (i < input.length()) {
        if (input[i] == '(' || input[i] == '[') {
            paren.push(input[i]);
        } else if (input[i] == ')') {
            if (!paren.empty() && paren.top() == '(') {
                paren.pop();
            } else {
                return false;
            }
        } else if (input[i] == ']') {
            if (!paren.empty() && paren.top() == '[') {
                paren.pop();
            } else {
                return false;
            }
        }
        ++i;
    }
    return paren.empty();
}

int main() {
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input == ".") break;

        if (isBalanced(input)) {
            std::cout << "yes" << '\n';
        } else {
            std::cout << "no" << '\n';
        }
    }
    return 0;
}