#include <iostream>
#include <string>
#include <stack>

bool isVPS(std::string input) {
    std::stack<char> s;
    int i{ 0 };

    while (i < input.length()) {
        if (input[i] == '(') {
            s.push(input[i]);
        } else {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
        ++i;
    }
    return s.empty();
}

int main() {
    int T;
    std::cin >> T;
    for (int i=0; i<T; ++i) {
        std::string input;
        std::cin >> input;
        if (isVPS(input)) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
    return 0;
}