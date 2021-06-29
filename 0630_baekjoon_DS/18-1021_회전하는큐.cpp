#include <iostream>
#include <deque>
#include <algorithm>

int main() {

    int n, m, pos, cnt{ 0 }, left, right;
    std::cin >> n >> m;

    std::deque<int> num;
    for (int i=1; i<=n; ++i) {
        num.push_back(i);
    }

    for (int j=0; j<m; ++j) {
        std::cin >> pos;
        if (num.size() == 1) continue;

        auto itr = std::find(num.begin(), num.end(), pos); // iterator
        left = itr - num.begin();
        right = num.size() - left - 1;

        if (left <= right) { // left shift is faster
            while (num.front() != pos) {
                ++cnt;
                num.push_back(num.front());
                num.pop_front();
            }
            num.pop_front();
        } else { // right shift is faster
            while (num.front() != pos) {
                ++cnt;
                num.push_front(num.back());
                num.pop_back();
            }
            num.pop_front();
        }
    }

    std::cout << cnt << '\n';


    return 0;
}