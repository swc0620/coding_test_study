#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') { // 대문자
            answer += 'A' + (c + n - 'A')%26;
        } else if (c >= 'a' && c <= 'z'){ // 소문자
            answer += 'a' + (c + n - 'a')%26;
        } else { // 공백
            answer += c;
        }
    }
    return answer;
}