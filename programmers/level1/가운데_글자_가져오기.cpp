#include <string>

using namespace std;

string solution(string s) {
    string answer{ "" };
    int mid = s.length() / 2;
    if (s.length() % 2 == 1) {
        answer += s[mid]; // char이므로 바로 return은 불가
    } else {
        answer += s.substr(mid-1,2);
    }
    return answer;
}