#include <iostream>
#include <list>
#include <string>
using namespace std;

class Circle {
	list<int> li;

public:
	Circle(int num) {
		for (int i = 1; i <= num; i++) {
			li.push_back(i);
		}
	}

	void print(int k) {
		int cnt = -1;
		cout << "<";
		list<int>::iterator itr = li.begin();
		while (li.size() > 0) {
			for (int i = 1; i < k; i++) {
				if (itr == li.end()) {
					itr = li.begin();
				}
				itr++;
			}
			if (itr == li.end()) {
				itr = li.begin();
			}
			if (li.size() == 1) {
				cout << *(itr) << ">" << endl;
			}
			else {
				cout << *(itr) << ", ";
			}
			itr = li.erase(itr);
		}
	}
};

int main() {
	string cmd;
	getline(cin >> ws, cmd);
	string first = cmd.substr(0, cmd.find(' '));
	string second = cmd.substr(cmd.find(' ') + 1);
	int n = stoi(first);
	int k = stoi(second);
	Circle circle(n);
	circle.print(k);
}