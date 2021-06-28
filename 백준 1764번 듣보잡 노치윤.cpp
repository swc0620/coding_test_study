#include <iostream>
#include <list>
#include <vector>
#include<set>
#include<string>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<string> vec;
	set<string> result;
	int unheard;
	int unseen;
	cin >> unheard >> unseen;

	int cnt = 0;
	while (cnt < unheard) {
		string temp;
		getline(cin >> ws, temp);
		vec.insert(temp);
		cnt++;
	}
	int cnt_ = 0;
	while (cnt_ < unseen) {
		string temp;
		getline(cin >> ws, temp);
		if (vec.find(temp) != vec.end()) {
			result.insert(temp);
		}
		cnt_++;
	}
	cout << result.size() << endl;
	for (set<string>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *(iter) << endl;
	}
}