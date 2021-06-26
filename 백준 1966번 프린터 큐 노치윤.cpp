#include <iostream>
#include <list>
#include <string>

class Arr {
public:
	int index;
	int num;
	Arr(int index, int num) {
		this->index = index;
		this->num = num;
	}
};

int main() {
	int num;
	std::cin >> num;
	for (int i = 1; i <= num; i++) {
		std::string a;
		std::list<Arr> qu;
		int len;
		int interest;
		std::cin >> len >> interest;
		int n;
		for (int j = 1; j <= len; j++) {
			std::cin >> n;
			Arr temp1(j - 1, n);
			qu.push_back(temp1);
		}

		int cnt = 0;
		while (true) {
			int check = 0;
			if (qu.size() != 0) {
				Arr temp = qu.front();
				for (std::list<Arr>::iterator iter = qu.begin(); iter != qu.end(); iter++) {
					if (temp.num < (*iter).num) {
						check = 1;
						qu.pop_front();
						qu.push_back(temp);
						break;
					}
				}
				if (check == 0) {
					cnt++;
					qu.pop_front();
					if (temp.index == interest) {
						std::cout << cnt << std::endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}