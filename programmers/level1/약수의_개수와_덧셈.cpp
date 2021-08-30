#include <cmath>

using namespace std;

// 단 하나의 수만 비교하도록 만들어 효율성 최대화
// -> 제곱근을 살펴본다

int solution(int left, int right) {
    int answer{ 0 };

    for (int n=left; n<=right; ++n) {
        if (sqrt(n) - (int) sqrt(n) == 0) { // 소수부가 남는가
            answer -= n;
        } else {
            answer += n;
        }
    }

    return answer;
}