#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> divisor;
    for (int i = 1; i <= sqrt(n); i++) {
        if (i * i == n) {
            divisor.push_back(i);
            break;
        }
        if (n % i == 0) {
            divisor.push_back(i);
            divisor.push_back(n / i);
        }
    }
    for (int i = 0; i < divisor.size(); i++) {
        answer += divisor[i];
    }
    return answer;
}