#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i=1; i <= s.size() / 2; i++){
        int cnt = 1;    // 같은 문자의 개수
        int tmp = 0;    // 압축한 문자열의 총 크기
        string current = s.substr(0, i);    // s[0] ~ s[i]개 까지 자른 문자열
        
        for(int j=i; j < s.size(); j+=current.size()){
            if(current == s.substr(j, i))
                cnt++;
            else{
                if(cnt == 1) tmp += current.size();     // 같은 문자가 1번 나오면 1은 생략
                else tmp += (to_string(cnt).size() + current.size());
                
                current = s.substr(j, i);
                cnt = 1;
            }
        }
        // 마지막 문자열의 길이 계산
        if(cnt == 1) tmp += current.size();
        else tmp += (to_string(cnt).size() + current.size());
        
        answer = min(answer, tmp);
    }
    return answer;
}