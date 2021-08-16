#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct separated_names
{
	string HEAD, ORIGINAL_NAME;
	int NUMBER;
};

bool cmp(separated_names a, separated_names b) {
	if (a.HEAD != b.HEAD) //HEAD가 다른 경우 HEAD 사전순 정렬
		return a.HEAD < b.HEAD;
	else //HEAD가 같은 경우 NUMBER 크기순 정렬
		return a.NUMBER < b.NUMBER;
}

vector<string> solution(vector<string> files) {
	vector <separated_names> separated_names(files.size());
	for (int i = 0; i < files.size(); i++) {
		int j = 0;
		while (!isdigit(files[i][j])) j++;
		int k = j;
		while (isdigit(files[i][k])) {
			k++;
			if (k - j >= 5) //NUMBER는 최대 5자리
				break;
		}
		separated_names[i].ORIGINAL_NAME = files[i]; //기존 파일명 저장
		transform(files[i].begin(), files[i].begin() + j, files[i].begin(), ::toupper); //대문자로 변환
		separated_names[i].HEAD = files[i].substr(0, j); //숫자 전까지의 string을 HEAD에 저장
		separated_names[i].NUMBER = stoi(files[i].substr(j, k - j)); //첫 연속된 숫자를 NUMBER에 저장
	}

	stable_sort(separated_names.begin(), separated_names.end(), cmp); //안정 정렬

	vector <string> answer;
	for (int i = 0; i < separated_names.size(); i++)
		answer.push_back(separated_names[i].ORIGINAL_NAME);

	return answer;
}