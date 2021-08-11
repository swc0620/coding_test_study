#include <string>
#include <vector>

using namespace std;

string toBinary(int n) {
    string result{ "" };
    while (n > 0) {
        result += to_string(n % 2);
        n /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer{ 0,0 }; // 이진변환의 횟수, 제거된 모든 0의 개수

    while (s != "1") {
        // 0 제거
        string tmp{ "" };
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '0')
                ++answer[1];
            else
                tmp += "1";
        }

        // 이진변환        
        s = toBinary(tmp.length());

        ++answer[0];
    }
    return answer;
}