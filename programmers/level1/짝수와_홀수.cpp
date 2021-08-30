#include <string>

using namespace std;

string solution(int num) {
    string answer = (num % 2 == 0) ? "Even" : "Odd"; // 비트 연산자 쓰면 조건문에 n & 1
    return answer;
}