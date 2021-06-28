#include <iostream>
#include <list>
#include <vector>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char input;
	while (true) {;
		vector<char> vec;
		vector<char> temp;
		input = cin.get();
		if (input == '.') {
			return 0;
		}
		if (input == '(' || input == '[' || input == ']' || input == ')') {
			vec.push_back(input);
		}
		while (true) {
			input = cin.get();
			if (input == '.') {
				int size = vec.size();
				int check = 0;
				for (int i = 0; i < size; i++) {
					char tem = vec.back();
					if (tem == ')' || tem == ']') {
						temp.push_back(tem);
						vec.pop_back();
					}
					else if (temp.size()!=0&&tem == '(' && temp.back() == ')') {
						vec.pop_back();
						temp.pop_back();
					}
					else if (temp.size() != 0 &&tem == '[' && temp.back() == ']') {
						vec.pop_back();
						temp.pop_back();
					}
					else {
						cout << "no" << endl;
						check = 1;
						while (std::cin.get() != '\n');
						break;
					}
				}
				if (check == 1) {
					break;
				}
				if (temp.size() != 0) {
					cout << "no" << endl;
					while (std::cin.get() != '\n');
					break;
				}
				cout << "yes" << endl;
				while (std::cin.get() != '\n');
				break;
			}
			if (input == '(' || input == '[' || input == ']' || input == ')') {
				vec.push_back(input);
			}
		}
	}

}