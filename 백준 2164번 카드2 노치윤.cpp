#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	deque<int> deck;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		deck.push_back(i);
	}
	if (deck.size() == 1) {
		cout << deck.front() << endl;
		return 0;
	}
	while (true) {
		deck.pop_front();
		int temp = deck.front();
		if (deck.size() == 1) {
			cout << deck.front() << endl;
			break;
		}
		deck.pop_front();
		deck.push_back(temp);
	}
	return 0;

}