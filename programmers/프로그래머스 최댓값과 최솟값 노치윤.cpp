#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    int idx = 0;//처음 나오는 빈칸의 인덱스가 저장될 변수
    while (true) {//min 과 max를 첫 번째 나오는 숫자로 초기화 하기 위해 첫번째 숫자를 찾는다.
        if (s[idx] == ' ') break;
        temp += s[idx];
        idx++;
    }
    int min = stoi(temp);
    int max = stoi(temp);
    temp = "";
    s += " ";//"숫자+빈칸" 기준으로 자르기 위해 맨 마지막에도 빈칸을 추가해줌.
    for (int i = idx + 1; i < s.length(); i++) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        if (s[i] == ' ') {
            if (min > stoi(temp)) min = stoi(temp);
            if (max < stoi(temp)) max = stoi(temp);
            temp = "";
        }
    }
    answer += to_string(min) + " ";
    answer += to_string(max);
    return answer;
}