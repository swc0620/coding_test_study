#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    int n, x;
    std::cin >> n;

    std::priority_queue<int> max_heap;
    for (int i=0; i<n; ++i) {
        std::cin >> x;
        if (x > 0) {
            max_heap.push(x);
        } else {
            if (max_heap.empty()) {
                std::cout << 0 << '\n';
            } else {
                std::cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
    }
    return 0;
}