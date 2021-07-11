#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long n_ = sqrt(n);
    if (n_ * n_ == n) {
        answer = (sqrt(n) + 1) * (sqrt(n) + 1);
    }
    else {
        answer = -1;
    }
    return answer;
}