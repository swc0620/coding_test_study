#include <iostream>
#include <map>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {
	map<int, int> m;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int temp;
		scanf("%d", &temp);
		if (m.find(temp) != m.end()) {
			m[temp]++;
		}
		else {
			m[temp] = 1;
		}
	}
	int cnt;
	scanf("%d", &cnt);
	string result = "";
	int input;
	scanf("%d", &input);
	if (m.find(input) == m.end()) {
		result += "0";
	}
	else {
		result += to_string(m[input]);
	}
	for (int i = 1; i < cnt; i++) {
		scanf("%d", &input);
		if (m.find(input) == m.end()) {
			result += " 0";
		}
		else {
			result += " " + to_string(m[input]);
		}
	}
	cout << result << endl;

}