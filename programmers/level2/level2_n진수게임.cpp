#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
// 진수 변환
string cal(int d, int n) {
    string res = "";
    char code[]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while (d/n != 0) {
        res = code[d%n] + res;
        d /=n;
    }
    res = code[d%n] + res;
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    for (int i =0; i <t*m ; i++) { 
         tmp += cal(i, n);
    }
    int cnt = 0;
    // 튜브의 순서가 p 일 때, 배열의 순서는 p-1이다.
    // m명의 사람이 있으므로, m 씩 더해야 한다.
    // cnt를 이용해 말해야 하는 숫자 t와 값을 비교한다.
    for (int i = p-1;  i < tmp.size(); i += m) {
        answer += tmp[i];
        if (cnt + 1 == t) break;
        cnt += 1;
    }
    return answer;
}
