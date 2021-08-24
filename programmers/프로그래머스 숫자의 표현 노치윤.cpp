#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    //x부터 연속된 a개의 합 = (2x+a-1)*a/2=n => 2n=(2x+a-1)*a
    //x 와 a 는 모두 자연수 이므로 (2x+a-1) > a , (2x+a-1)와 a (홀수. 짝수) , (짝수, 홀수)
    n *= 2;
    for (int i = 1; i * i < n; i++) {
        if (n % i == 0) {
            if ((i + n / i) % 2 == 1) answer++;
            //n/i 는 (2x+a-1), i는 a에 해당. 홀수, 짝수 이여야 하므로 합은 홀수 인지 체크.
        }
    }
    return answer;
}