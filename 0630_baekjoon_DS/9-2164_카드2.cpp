#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::queue<int> card;
    for (int i=1; i<=n; ++i) {
        card.push(i);
    }

    while (card.size() > 1) {
        card.pop();
        int tmp = card.front();
        card.pop();
        card.push(tmp);
    }
    std::cout << card.front() << '\n';
    
    return 0;
}