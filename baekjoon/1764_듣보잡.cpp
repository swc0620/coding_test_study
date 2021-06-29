#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	std::set<std::string> temp;
	std::set<std::string> result;

	for (int i=0; i<n; i++){
		std::string s;
		std::cin >> s;
		temp.insert(s);
	}

	int cnt = 0;

	for (int i=0; i<m; i++){
		std::string s;
		std::cin >> s;
		if (temp.find(s) != temp.end()) {
			result.insert(s);
			cnt++;
		}

	}
	std::cout << cnt << '\n';

	for (std::string s : result){
		std::cout << s << '\n';
    }

	return 0;
}

/* 
s.find(k);
- 원소 k를 가리키는 반복자를 반환
- 원소 k가 없다면 s.end() 와 같은 반복자를 반환
*/
