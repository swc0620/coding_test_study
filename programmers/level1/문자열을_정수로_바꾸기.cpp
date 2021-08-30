#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool plus = true;
    if (s.front() == '+') {
        s = s.erase(0,1);
    } else if (s.front() == '-') {
        s = s.erase(0,1);
        plus = false;
    }
    
    answer = stoi(s);
    if (!plus) answer *= -1;
    return answer;
}


// stoi 함수는 부호처리도 알아서 해줌
// 실질적으로 stoi(s)만 해주면 끝나는 문제