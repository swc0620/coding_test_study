#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while (a != b) {
        a = (a / 2) + (a % 2); // 홀수일 경우 +1
        b = (b / 2) + (b % 2);
        ++answer; // 한 라운드의 끝
    }

    return answer;
}