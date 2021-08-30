#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 1; // 2 포함
    bool isPrime; // 초기화 횟수 줄임

    for (int i=3; i<=n; i+=2) { // 홀수만 판별
        isPrime = true;
        for (int j=3; j<=(int) sqrt(i); j+=2) { // 홀수만 나누는 수로 사용
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) ++answer;
    }
    return answer;
}