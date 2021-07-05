#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        answer += i;
    }
    int left_ = sqrt(left);
    int right_ = sqrt(right);
    if (left != left_ * left_) {
        left_ = left_ + 1;
    }
    for (int i = left_; i <= right_; i++) {
        answer -= 2 * i * i;
    }
    return answer;
}