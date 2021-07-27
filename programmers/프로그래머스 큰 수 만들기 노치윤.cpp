#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start_idx = 0;
    int cnt = 0;
    int length = number.length() - k;//k개를 제외한 문자열 길이
    while (cnt < length) {
        int idx = 0;
        char max = '0' - 1;//문자열 내에 0이 있을 수 있으므로 1을 빼줌.
        for (int i = start_idx; i <= number.length() - (length - cnt); i++) {
            if (number[i] > max) {
                max = number[i];
                idx = i;
            }
        }
        answer += max;
        start_idx = idx + 1;
        cnt++;
    }
    return answer;
}