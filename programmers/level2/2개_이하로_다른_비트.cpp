#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long number : numbers) {
        // 짝수
        if (number % 2 == 0) {
            answer.push_back(number + 1); // 최하위 비트가 항상 0이므로 1만 더해주면 최소
        // 홀수
        } else {
            // 현재 수보다 커야 함 -> 가장 오른쪽에 있는 0을 1로 바꿈
            // 증가를 더 줄일 수 있는 방법 -> 그다음 1을 0으로. 홀수는 항상 1로 끝나므로 최하위 0과 1은 붙어있음
            long long bit = 1;
            while ((number & bit) > 0) { // 0111 & 0001 = 0111
                bit <<= 1; // 왼쪽으로 밀어준다 -> 0010
            } // 0111 & 1000 = 0000 -> 위치 찾아냄
            answer.push_back(number + bit - (bit >> 1)); // bit를 더하면 최하위 0을 1로. bit >> 1하면 최하위 0 다음 자리의 1이 0으로 감소됨
        }
    }
    return answer;
}