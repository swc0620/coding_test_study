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
	Stack stack;
	int cnt;
	std::cin >> cnt;
	int i = 0;
	while (i < cnt) {
		std::string cmd;
		getline(std::cin >> std::ws, cmd);
		if (cmd.length() >= 6) {
			std::string num = cmd.substr(5);
			stack.push(std::stoi(num));
		}
		else if (cmd.compare("pop") == 0) {
			std::cout << stack.pop() << std::endl;
		}
		else if (cmd.compare("size") == 0) {
			std::cout << stack.size() << std::endl;
		}
		else if (cmd.compare("empty") == 0) {
			std::cout << stack.empty() << std::endl;
		}
		else if (cmd.compare("top") == 0) {
			std::cout << stack.top() << std::endl;
		}
		i++;
	}
}