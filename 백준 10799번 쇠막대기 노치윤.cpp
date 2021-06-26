#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	vector<char> vec;
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		vec.push_back(a[i]);
	}
	vector<int> vec_;
	int num_bar = 0;
	vec_.push_back(0);
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] == '(') {
			vec_.push_back(vec_.back() + 1);
		}
		else if (vec[i] == ')') {
			if (vec[i - 1] == ')') {
				num_bar++;
			}
			vec_.push_back(vec_.back() - 1);
		}
	}

	for (int i = 0; i < vec_.size() - 1; i++) {
		if (vec[i] == '(' && vec[i + 1] == ')') {
			num_bar += vec_[i];
		}
	}
	std::cout << num_bar << endl;

}