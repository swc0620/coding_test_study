#include <string>
#include <vector>
using namespace std;

char change(char a) {
    if (a >= 'a' && a < 'z' || a >= 'A' && a < 'Z') {
        a += 1;
    }
    else if (a == 'z') {
        a = 'a';
    }
    else if (a == 'Z') {
        a = 'A';
    }
    return a;
}
string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.length(); i++) {
        int cnt = 0;
        char temp = s[i];
        while (cnt < n) {//n칸 이동시켜주는 반복문
            temp = change(temp);
            cnt++;
        }
        answer += temp;
    }
    return answer;
}