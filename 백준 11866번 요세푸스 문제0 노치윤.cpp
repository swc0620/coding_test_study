#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	vector<int> qu;
	int num, interest;
	cin >> num >> interest;

	for (int i = 1; i <= num; i++) {
		qu.push_back(i);
	}

	vector<int>::iterator iter = qu.begin();
	cout << "<";
	while (true) {
		if (qu.size() == 1) {
			break;
		}
		for (int i = 0; i < interest - 1; i++) {
			if (iter == qu.end()) {
				iter = qu.begin();
			}
			iter++;
		}
		if (iter == qu.end()) {
			iter = qu.begin();
		}
		cout << *(iter) << ", ";
		iter = qu.erase(iter);
	}
	cout << qu[0] << ">" << endl;


}
