#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            if (idx % 2 == 0) answer += toupper(s[i]);
            else answer += tolower(s[i]);
            idx++;
        }
        else {//공백이 나온다면 다시 index를 0으로 만들어줌
            idx = 0;
            answer += ' ';
        }
    }

    return answer;
}