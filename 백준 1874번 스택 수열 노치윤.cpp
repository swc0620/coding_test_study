#include <iostream>
#include <vector>
#include <string>

int main() {
	int num;
	std::vector<int> vec;
	std::vector<int> num_list;
	std::cin >> num;
	int cnt = 0;
	while (cnt < num) {
		std::string a;
		std::getline(std::cin >> std::ws, a);
		int num_a = stoi(a);
		vec.push_back(num_a);
		cnt++;
	}

	int count = 0;
	std::string result = "";
	num_list.push_back(1);
	result += "+";
	int push = 2;
	while (count != num) {
		if (num_list.size() == 0) {
			num_list.push_back(push++);
			result += "\n+";
		}
		if (vec[count] > num_list[num_list.size() - 1] || num_list.size() == 0) {
			num_list.push_back(push++);
			result += "\n+";
		}
		else if (vec[count] == num_list[num_list.size() - 1]) {
			count++;
			result += "\n-";
			num_list.pop_back();
		}
		else {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	std::cout << result;

}