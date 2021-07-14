#include <string>
using namespace std;

int solution(int num) {
    int answer = 0;
    long long num_ = num;
    while (true) {
        if (num_ == 1) {
            break;
        }

        if (num_ % 2 == 0) num_ /= 2;
        else num_ = num_ * 3 + 1;
        answer++;
        if (answer == 500) {
            answer = -1;
            break;
        }

    }
    return answer;
}