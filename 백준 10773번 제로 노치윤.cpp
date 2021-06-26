#include <iostream>
#include <vector>
#include <string>

int main() {
	int num;
	std::vector<long> vec;
	std::cin >> num;
	for (int i = 0; i < num; i++) {
		int k;
		std::cin >> k;
		if (k == 0) {
			vec.pop_back();
		}
		else {
			vec.push_back(k);
		}
	}
	int sum = 0;
	for (std::vector<long>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		sum += (*iter);
	}
	std::cout << sum << std::endl;
}