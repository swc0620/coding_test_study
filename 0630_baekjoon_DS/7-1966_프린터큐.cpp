#include <iostream>
#include <queue>

int main() {
    int test;
    std::cin >> test;

    for (int i=0; i<test; ++i) {
        int num, target, cnt{ 0 };
        std::cin >> num >> target;

        std::queue<std::pair<int,int>> printer;
        std::priority_queue<int> priority;

        for (int j=0; j<num; ++j) {
            int importance;
            std::cin >> importance;
            printer.push(std::make_pair(j,importance));
            priority.push(importance);
        }

        while (!printer.empty()) {
            int idx = printer.front().first;
            int val = printer.front().second;
            printer.pop();
            if (priority.top() == val) {
                priority.pop();
                ++cnt;
                if (idx == target) {
                    std::cout << cnt << '\n';
                    break;
                }
            } else {
                printer.push(std::make_pair(idx,val));
            }
        }
    }

    return 0;
}