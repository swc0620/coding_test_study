#include <iostream>
#include <list>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	cin >> input;
	list<char> vec;
	for (int i = 0; i < input.length(); i++) {
		vec.push_back(input[i]);
	}
	int cursor = 0;
	int cmd;
	cin >> cmd;
	int cnt = 0;
	list<char>::iterator iter = vec.end();
	while (cnt < cmd) {
		char temp;
		cin >> temp;
		if (temp=='L') {
			if (iter == vec.begin()) {
				cnt++;
				continue;
			}
			else {
				iter--;
			}
		}
		else if (temp=='D') {
			if (iter == vec.end()) {
				cnt++;
				continue;
			}
			else {
				iter++;
			}
		}
		else if (temp=='B') {
			if (iter == vec.begin()) {
				cnt++;
				continue;
			}
			else {
				iter--;
				iter = vec.erase(iter);
			}
		}
		else if (temp=='P') {
			char in;
			cin >> in;
			iter=vec.insert(iter, in);
			iter++;
		}
		cnt++;
	}
	for (list<char>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		cout << *(itr);
	}
	cout << "\n";
}