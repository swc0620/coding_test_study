#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a == b) {
        return a;
    }
    long long min = (a < b) ? a : b;
    long long max = (a > b) ? a : b;
      
    for (int i=min; i<=max; ++i) {
        answer += i;
    }
    
    return answer;
}