#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    int num_cards, card;
    std::cin >> num_cards;
    int cards[num_cards];
    for (int i=0; i<num_cards; ++i) {
        std::cin >> card;
        cards[i] = card;
    }
    std::vector<int> v(cards, cards+num_cards);
    std::sort(v.begin(), v.end());

    int num_tests, test;
    std::cin >> num_tests;
    for (int j=0; j<num_tests; ++j) {
        std::cin >> test;
        std::vector<int>::iterator low, high;
        low = std::lower_bound(v.begin(), v.end(), test);
        high = std::upper_bound(v.begin(), v.end(), test);
        std::cout << high-low << ' ';
    }

    return 0;
}