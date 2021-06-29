#include <iostream>
#include <queue>
#include <sstream>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<int> ppl;
    for (int i=1; i<=n; ++i) {
        ppl.push(i);
    }

    std::stringstream out;
    out << '<';

    while (ppl.size() > 1) {
        for (int j=1; j<k; ++j) {
            int kth = ppl.front();
            ppl.pop();
            ppl.push(kth);
        }
        out << ppl.front() << ", ";
        ppl.pop();
    }
    out << ppl.front() << '>';
    ppl.pop();
    std::cout << out.str() << '\n';
    return 0;
}