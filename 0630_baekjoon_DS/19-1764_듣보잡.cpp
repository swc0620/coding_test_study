#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string name;

    std::vector<std::string> not_heard; // ordered
    std::vector<std::string> not_both;
    not_heard.resize(n);

    for (int i=0; i<n; ++i) {
        std::cin >> not_heard[i];
    }
    std::sort(not_heard.begin(), not_heard.end());

    for (int j=0; j<m; ++j) {
        std::cin >> name;
        if (std::binary_search(not_heard.begin(), not_heard.end(), name)) {
            not_both.push_back(name);
        }
    }
    std::sort(not_both.begin(), not_both.end());

    std::cout << not_both.size() << '\n';
    for (std::string ans : not_both) {
        std::cout << ans << '\n';
    }
    return 0;
}