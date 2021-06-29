#include <iostream>
#include <stack>
#include <string>
 
int main() {
    std::string s;
    std::cin >> s;
    std::stack<char> l;
    std::stack<char> r;

    for (int i = 0; i < s.size(); i++) {
        l.push(s[i]);
    }

    int num;
    std::cin >> num;
    while (num--) {
        char tmp;
        std::cin >> tmp;

        if (tmp == 'P') {
            char c;
            std::cin >> c;
            l.push(c);
        }

        else if (tmp == 'L') {
            if (l.empty()){
                continue;
            }
            else {
                r.push(l.top());
                l.pop();
            }
        }

        else if (tmp == 'B') {
            if (l.empty()){
                continue;
            }
            else {
                l.pop();
            }
        }

        else if (tmp == 'D') {
            if (r.empty()){
                continue;
            }
            else {
                l.push(r.top());
                r.pop();
            }
        }
    }

    // abcd라면
    while (!l.empty()) {
        r.push(l.top());        // r에 dcba 순으로 들어가고
        l.pop();
    }

    while (!r.empty()) {
        std::cout << r.top();   // 나중에 출력은 abcd순으로 출력 후 r 나머지 출력
        r.pop();
    }

    return 0;
}