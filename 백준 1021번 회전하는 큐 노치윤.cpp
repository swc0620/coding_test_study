#include <iostream>
#include <list>
#include <vector>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
void oper2(list<int>& li);
void oper3(list<int>& li);
int find_index(list<int>& li, int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	list<int> li;
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		li.push_back(i);
	}
	int count;
	cin >> count;
	vector<int> vec;
	int cnt = 0;
	while (cnt < count) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
		cnt++;
	}
	int result = 0;
	while (vec.size() != 0) {
		int oper = find_index(li,vec.front());
		if (oper == 2) {
			while (li.front() != vec.front()) {
				oper2(li);
				result++;
			}
		}
		else if (oper == 3) {
			while (li.front() != vec.front()) {
				oper3(li);
				result++;
			}
		}
		vec.erase(vec.begin());
		li.pop_front();
	}
	cout << result << endl;
}

int find_index(list<int>& li, int num) {
	int size = li.size();
	int index = 1;
	for (list<int>::iterator iter = li.begin(); iter != li.end(); iter++) {
		if (num == *(iter)) {
			break;
		}
		index++;
	}

	if (size % 2 == 0) {
		if ((size / 2) < index) {
			return 3;
		}
		else {
			return 2;
		}
	}
	else {
		if ((size / 2)+1 < index) {
			return 3;
		}
		else {
			return 2;
		}
	}
}

void oper2(list<int>& li) {
	int temp = li.front();
	li.pop_front();
	li.push_back(temp);
}

void oper3(list<int>& li) {
	int temp = li.back();
	li.pop_back();
	li.push_front(temp);
}