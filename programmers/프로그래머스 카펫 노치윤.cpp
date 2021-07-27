#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = ((brown + yellow) - yellow - 4) / 2;//yellow: 가로*세로, brown+yellow: (가로+2)*(세로+2) -> 2*가로+2*세로=(brown + yellow) - yellow - 4
    int cross = yellow;
    int n = (sum + sqrt(sum * sum - 4 * cross)) / 2;//근의 공식, yellow 가로
    int m = (sum - sqrt(sum * sum - 4 * cross)) / 2;//근의 공식, yellow 세로
    answer.push_back(n + 2);
    answer.push_back(m + 2);
    return answer;
}