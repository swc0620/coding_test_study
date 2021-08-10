string longestPalindrome(string s)
{
	// First get rid of those really long and palindrome cases.
	if (s == string(s.rbegin(), s.rend())){
		return s;
	}

	int start = 0, end = 0;
	set<pair<int, int>> pairs;

	// 1이면 무조건 palindrome, 2부터 시작
	for (int c = 2; c <= s.length(); c++){
		int i = 0;
		int j = i + c - 1;
		while (j < s.length()){
			if (s[i] == s[j]){
				if (j - i < 3){
					pairs.insert(pair<int, int>(i, j));
					if (j - i > end - start){
						start = i;
						end = j;
					}
				}
				else if (pairs.find(pair<int, int>(i + 1, j - 1)) != pairs.end()){
					pairs.insert(pair<int, int>(i, j));
					if (j - i > end - start) {
						start = i;
						end = j;
					}
				}
			}
			++i;
			j = i + c - 1;
		}
	}
	return s.substr(start, end - start + 1);
}