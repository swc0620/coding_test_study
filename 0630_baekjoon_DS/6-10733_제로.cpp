#include <iostream>
#include <stack>

int main() {
    int k;
    std::cin >> k;
    std::stack<int> num;
    int sum{ 0 };

    for (int i=0; i<k; ++i) {
        int n;
        std::cin >> n;
        if (n == 0) {
            int temp = num.top();
            num.pop();
            sum -= temp;
        } else {
            num.push(n);
            sum += n;
        }
    }
    std::cout << sum << '\n';

    return 0;
}