#include <iostream>
#include <stack>

int main() {
    std::string input;
    int m;
    std::cin >> input >> m;
    
    // 커서 기준 양쪽으로 스택 선언
    std::stack<char> left;
    std::stack<char> right;
    for (char c : input) {
        left.push(c); // 초기 커서는 문장 맨 뒤에 위치
    }

    char command;
    for (int i=0; i<m; ++i) {
        std::cin >> command;
        if (command == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (command == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (command == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } else {
            char c;
            std::cin >> c;
            left.push(c);
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        std::cout << right.top();
        right.pop();
    }
    return 0;
}