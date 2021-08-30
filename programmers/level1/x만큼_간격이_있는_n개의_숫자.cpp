#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer{ x };
    long long seq = (long long) x;
        
    for (int i=1; i<n; ++i) {
        seq += (long long) x;
        answer.push_back(seq);
    }
    return answer;
}