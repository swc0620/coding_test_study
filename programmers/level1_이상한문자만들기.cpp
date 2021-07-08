#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int count = 0;  
    for (int i=0; i<s.size(); i++){
        if (s[i] !=  ' '){
            if (count%2 == 0){
                answer += toupper(s[i]);
            }
            else{
                answer += tolower(s[i]);
            }
            count += 1;
        }
        else{
            answer += ' ';
            count = 0; // 공백 만나면 인덱스 리셋
        }
    }
    return answer;
}