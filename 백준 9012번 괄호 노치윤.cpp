#include <iostream>
#include <vector>
#include <string>

class Stack {
private:
	std::vector<int> vec;

public:
	void push(int x) {
		vec.push_back(x);
	}

	int pop() {
		if (vec.size() != 0) {
			int a = vec[vec.size() - 1];
			vec.pop_back();
			return a;
		}
		else {
			return -1;
		}
	}

	int size() {
		return vec.size();
	}

	int empty() {
		if (vec.size() == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int top() {
		if (vec.size() == 0) {
			return -1;
		}
		else {
			return vec[vec.size() - 1];
		}
	}
};

int main() {
	int cnt;
	std::cin >> cnt;
	int k = 0;
	while (k < cnt) {
		Stack temp;
		std::string cmd;
		int check = 0;
		getline(std::cin >> std::ws, cmd);
		if (cmd.length() % 2 == 1) {
			std::cout << "NO" << std::endl;
			check = 1;
		}
		else {
			for (int i = cmd.length() - 1; i >= 0; i--) {
				if (cmd[i] == ')') {
					temp.push(2);
				}
				else {
					if (temp.empty() == 1) {
						std::cout << "NO" << std::endl;
						check = 1;
						break;
					}
					else {
						temp.pop();
					}
				}
			}
		}
		if (temp.empty() == 0) {
			std::cout << "NO" << std::endl;
			check = 1;
		}
		if (check == 0) {
			std::cout << "YES" << std::endl;
		}
		k++;
	}
}