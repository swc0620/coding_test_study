#include <string>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;
    
    int n = len / 2; // 최대 압축 단위
    
    for (int i=1; i<=n; ++i) { // 압축 단위
        string result = ""; // 압축한 문자열
        string unit = s.substr(0,i); // 첫번째 substring
        
        int cnt = 1;
        for (int j=i; j<=len; j+=i) { // 비교할 문자열 단위
            if (s.substr(j,i) == unit) { // 문자 반복
                ++cnt;
            } else {
                if (cnt == 1) { // 압축 불가
                    result += unit; // 그대로 붙이기
                } else {
                    result += (to_string(cnt) + unit); // 반복횟수 앞에 붙이기
                }
                unit = s.substr(j,i); // 새로운 문자 시작
                cnt = 1;
            }
        }
        
        if (len%i > 0) {
            result += s.substr((len / i)*i); //s.substr(len-len%i,len%i); // 자투리 붙이기
        }
        if (answer > result.length()) {
            answer = result.length();
        }
    }
    return answer;
}