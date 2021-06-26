#include <iostream>
#include <deque>
#include <string>
using namespace std;

class Deque {
	deque<int> deck;
public:

	void push_front(int x) {
		deck.push_front(x);
	}

	void push_back(int x) {
		deck.push_back(x);
	}

	int pop_front() {
		if (deck.size() == 0) {
			return -1;
		}
		else {
			int temp = deck.front();
			deck.pop_front();
			return temp;
		}
	}
	int pop_back() {
		if (deck.size() == 0) {
			return -1;
		}
		else {
			int temp = deck.back();
			deck.pop_back();
			return temp;
		}
	}
	int size() {
		return deck.size();
	}
	int empty() {
		if (deck.size() == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int front() {
		if (deck.size() == 0) {
			return -1;
		}
		else {
			return deck.front();
		}
	}
	int back() {
		if (deck.size() == 0) {
			return -1;
		}
		else {
			return deck.back();
		}
	}
};

int main() {
	Deque de;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		string temp;
		cin >> temp;
		if (temp.compare("push_back") == 0) {
			int a;
			cin >> a;
			de.push_back(a);
		}
		else if (temp.compare("push_front") == 0) {
			int a;
			cin >> a;
			de.push_front(a);
		}
		else if (temp.compare("pop_front") == 0) {
			cout << de.pop_front() << endl;
		}
		else if (temp.compare("pop_back") == 0) {
			cout << de.pop_back() << endl;
		}
		else if (temp.compare("size") == 0) {
			cout << de.size() << endl;
		}
		else if (temp.compare("empty") == 0) {
			cout << de.empty() << endl;
		}
		else if (temp.compare("front") == 0) {
			cout << de.front() << endl;
		}
		else if (temp.compare("back") == 0) {
			cout << de.back() << endl;
		}
	}
	return 0;
}