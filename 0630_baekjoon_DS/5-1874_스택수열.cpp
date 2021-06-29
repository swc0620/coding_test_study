#include <iostream>
#include <stack>
#include <vector>

int main() {
    int n, num, idx{ 0 };
    std::cin >> n;

    std::vector<int> input;
    input.reserve(n);

    for (int i=0; i<n; ++i) {
        std::cin >> num;
        input.push_back(num);
    }

    std::vector<char> output;
    std::stack<int> stack;

    for (int i=1; i<=n; ++i) {
        stack.push(i);
        output.push_back('+');
        
        while (!stack.empty()) {
            if (stack.top() == input.at(idx)) {
                stack.pop();
                output.push_back('-');
                ++idx;
            } else {
                break;
            }
        }
    }

    if (stack.empty()) {
        for (char oper : output) {
            std::cout << oper << '\n';
        }
    } else {
        std::cout << "NO" << '\n';
    }

    return 0;
}