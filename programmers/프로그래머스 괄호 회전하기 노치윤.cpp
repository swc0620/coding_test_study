#include <string>
#include <vector>

using namespace std;

bool complete(string s) {
    vector<char> temp;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') temp.push_back(s[i]);
        else if (s[i] == '(') {
            if (temp.size() == 0) return false;
            if (temp.back() == ')') temp.pop_back();
            else return false;
        }
        else if (s[i] == '[') {
            if (temp.size() == 0) return false;
            if (temp.back() == ']') temp.pop_back();
            else return false;
        }
        else if (s[i] == '{') {
            if (temp.size() == 0) return false;
            if (temp.back() == '}') temp.pop_back();
            else return false;
        }
    }
    if (temp.size() != 0) return false;
    return true;
}
int solution(string s) {
    int answer = 0;
    int cnt = 0;
    while (cnt != s.length()) {
        string temp = s.substr(cnt) + s.substr(0, cnt);
        if (complete(temp)) answer++;
        cnt++;
    }
    return answer;
}