#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 시간 초과 원인
    // 1. <iostream> 표준 입출력은 수행할 때마다 C의 표준 입출력과 동기화되도록 설정
    // 2. C++은 다른 마지막으로 작업한 I/O 스트림이 아닌 다른 곳에서 입출력 작업하려고 할 때 입출력 버퍼를 비우는 작업을 수행하는데, 이 상태를 스트림이 Tied 되어있다
    // --> 다음과 같이 해결
    std::ios_base::sync_with_stdio(false); // C 표준 입출력과의 동기화를 하지 않도록 설정
	std::cin.tie(NULL); // 자동으로 스트림을 untie 시켜서 자동적으로 입출력 버퍼를 비우지 않도록 설정
	std::cout.tie(NULL);

    int n, x;
    std::cin >> n;

    std::priority_queue<int,std::vector<int>, std::greater<int>> min_heap;
    for (int i=0; i<n; ++i) {
        std::cin >> x;
        if (x > 0) {
            min_heap.push(x);
        } else {
            if (min_heap.empty()) {
                std::cout << 0 << '\n';
            } else {
                std::cout << min_heap.top() << '\n';
                min_heap.pop();
            }
        }
    }
    return 0;
}