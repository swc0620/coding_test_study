#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i=1; i<=sqrt(n); ++i) {
        if (i * i == n) { // 자연수의 제곱일 경우 (아래 if조건과 중첩되므로 위로 빼주기)
            answer += i;
        } else if (n % i == 0) {
            answer += i + (n/i); // divisor + quotient
        }
    }
    
    return answer;
}