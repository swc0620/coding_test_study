#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx; // comparator에 비교하고자 하는 두 대상 외에 다른 parameter 들어가지 못하므로 전역 변수 선언

bool compareByIdx(string &a, string &b) {
    if (a[idx] == b[idx]) {
        return a < b;
    }
    return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer(strings);
    idx = n;
    sort(answer.begin(), answer.end(), compareByIdx);
    return answer;
}