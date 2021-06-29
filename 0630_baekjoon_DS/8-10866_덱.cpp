#include <iostream>
#include <deque>

int main() {
    int N;
    std::cin >> N;

    std::deque<int> dq;

    for (int i=0; i<N; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "push_front") {
            int x;
            std::cin >> x;
            dq.push_front(x);

        } else if (command == "push_back") {
            int x;
            std::cin >> x;
            dq.push_back(x);

        } else if (command == "pop_front") {
            if (dq.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << dq.front() << '\n';
            dq.pop_front();

        } else if (command == "pop_back") {
            if (dq.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << dq.back() << '\n';
            dq.pop_back();

        } else if (command == "size") {
            std::cout << dq.size() << '\n';

        } else if (command == "empty") {
            std::cout << ((dq.empty()) ? 1 : 0) << '\n';

        } else if (command == "front") {
            if (dq.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << dq.front() << '\n';

        } else {
            if (dq.empty()) {
                std::cout << "-1" << '\n';
                continue;
            }
            std::cout << dq.back() << '\n';
        }
    }
    return 0;
}