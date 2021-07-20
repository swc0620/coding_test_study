#include <string>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    while (true) {//규칙: 1을 빼서 3으로 나눈 나머지를 구했을 때 0이면 1, 1이면 2, 2이면 4,~~~계속 반복
        if (n == 0) break;
        if ((n - 1) % 3 == 0) answer += to_string(1);
        else if ((n - 1) % 3 == 1) answer += to_string(2);
        else if ((n - 1) % 3 == 2) answer += to_string(4);
        n = (n - 1) / 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}