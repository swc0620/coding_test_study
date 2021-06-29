// 10799 쇠막대기

#include <iostream>
#include <string>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::stack<char> S;
	std::string input;
	int total = 0;
	std::cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			S.push(input[i]);
		}
		else if(input[i]==')' and input[i-1]=='('){ // 레이저일때
			S.pop();
			total += S.size();
		}
		else { // 마지막 자투리일때
			total++;
			S.pop();
		}
	}
	std::cout << total << std::endl;
}