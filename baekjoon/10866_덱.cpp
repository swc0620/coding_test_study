// 10866 덱

#include <iostream>
#include <deque>
 
int main(void){
    // 입출력 가속
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
 
	int N, X;
	std::deque<int> D;
	std::string op;
	std::cin >> N;
 
	for (int i = 0; i < N; i++) {
		std::cin >> op;
		if (op == "push_front") {
			std::cin >> X;
			D.push_front(X);
		}

		else if (op == "push_back") {
			std::cin >> X;
			D.push_back(X);
		}

		else if (op == "pop_front") {
			if (D.empty()){
                std::cout << -1 << '\n';
            }
			else {
				std::cout << D.front() << '\n';
				D.pop_front();
			}
		}

		else if (op == "pop_back") {
			if (D.empty()) {
                std::cout << -1 << '\n';
            }
			else {
				std::cout << D.back() << '\n';
				D.pop_back();
			}
		}

		else if (op == "size") {
			std::cout << D.size() << '\n';
		}

		else if (op == "empty") {
			std::cout << D.empty() << '\n';
		}

		else if (op == "front") {
			if (D.empty()){
                std::cout << -1 << '\n';
            }
			else {
                std::cout << D.front() << '\n';
            }
		}

		else if (op == "back") {
			if (D.empty()) {
                std::cout << -1 << '\n';
            }
			else {
                std::cout << D.back() << '\n';
            }
		}
	}
 
	return 0;
}