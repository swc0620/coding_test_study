#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string input;
    std::stack<char> s;
    std::cin >> input;

    int ans{ 0 };
    for (int i=0; i<input.size(); ++i) {
        if (input[i] == '(') {
            s.push('(');
        } else {
            s.pop();
            if (input[i-1] == '(') { // laser
                ans += s.size();
            } else { // end of rod
                ans += 1;
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}