#include <string>
#include <vector>
#include <iostream>
using namespace std;

string make_num(int n, int num) {
    string temp = "";
    if (num == 0) return "0";
    while (num != 0) {
        int R = num % n;
        string R_string = to_string(R);
        if (R >= 10) {
            if (R == 10) R_string = "A";
            if (R == 11) R_string = "B";
            if (R == 12) R_string = "C";
            if (R == 13) R_string = "D";
            if (R == 14) R_string = "E";
            if (R == 15) R_string = "F";
        }
        temp = R_string + temp;
        num /= n;
    }
    return temp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    int limit = m * (t - 1) + p;
    for (int i = 0; i <= limit; i++) {
        temp = temp + make_num(n, i);
        if (temp.length() >= limit) break;
    }
    //temp에는 0부터 적정(충분)길이까지 0 1 10 ~~(2진법인 경우) 저장
    for (int i = 0; i < temp.length(); i++) {
        if (i % m == (p - 1)) {
            answer = answer + temp[i];
        }
        if (answer.length() == t) break;
    }
    return answer;
}